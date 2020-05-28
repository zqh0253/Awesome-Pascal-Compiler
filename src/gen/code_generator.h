#ifndef LLVM_TEST_CODE_GENERATOR_H
#define LLVM_TEST_CODE_GENERATOR_H

#include "ast/ast.h"
#include "sem/sem.h"
#include "llvm.h"
#include "my_block.h"

#include <vector>

class CodeGenerator {
private:
	std::vector<MyBlock*> block_stack;

public:
	llvm::LLVMContext *context = nullptr;
	llvm::IRBuilder<> *ir_builder = nullptr;
	std::map<std::string, llvm::Module*> modules;
	llvm::Module *cur_module = nullptr;

	CodeGenerator() = default;

	CodeGenerator(llvm::LLVMContext *context) {
		this->context = context;
		if (context)
			this->ir_builder = new llvm::IRBuilder<>(*this->context);
	}

	void gencode(Node *root);
	void gencode_children(Node *root);

	static std::string get_entry_name(std::string& s) {
		return s + "_entry";
	}

	std::string local_func_name(std::string &name) {
		return local_sem()->name + "_" + name;
	}

	void push_block(MyBlock *block) {
		if (block) {
			block_stack.push_back(block);
			ir_builder->SetInsertPoint(block->bb);
		}
	}
	void push_block(llvm::BasicBlock *bb, sem::SemanticAnalyzer *sa) {
		push_block(new MyBlock(bb, sa));
	}
	void push_block(llvm::BasicBlock *bb, std::string &name) {
		push_block(new MyBlock(bb, new sem::SemanticAnalyzer(name)));
	}
	MyBlock *pop_block() {
		MyBlock *top = local_block();
		block_stack.pop_back();
		ir_builder->SetInsertPoint(local_bb());
		return top;
	}
	sem::SemanticAnalyzer *local_sem() { return local_block()->sa; }
	llvm::BasicBlock *local_bb() { return local_block()->bb; }
	MyBlock *local_block() { return get_block(block_stack.size() - 1); }
	MyBlock *get_block(int index) { return block_stack[index]; }
	MyBlock *global_block() { return get_block(0); }

	void add_module(std::string &name) {
		llvm::Module *module = new llvm::Module(name, *context);
		add_module(module);
	}
	void add_module(llvm::Module *module) {
		modules[module->getName().str()] = module;
		cur_module = module;
	}
	llvm::Module * get_module(std::string &name) {
		llvm::Module *ret = nullptr;
		if (modules.count(name)) {
			ret = modules[name];
		}
		return ret;
	}
	llvm::Instruction *alloc_local_variable(llvm::Type *type, std::string &name);
	llvm::Instruction *store_local_variable(std::string &name, llvm::Value *val);
	llvm::Constant *to_llvm_constant(ConstValue *c);
	llvm::Type *to_llvm_type(sem::SemType *type);

	llvm::Type *getIntTy() {
		return llvm::Type::getInt32Ty(*context);
	}

	llvm::Type *getVoidTy() {
		return llvm::Type::getVoidTy(*context);
	}

	llvm::Type *getCharTy() {
		return llvm::Type::getInt8Ty(*context);
	}

	llvm::Type *getRealTy() {
		return llvm::Type::getDoubleTy(*context);
	}

	llvm::Type *getBoolTy() {
		return llvm::Type::getInt1Ty(*context);
	}

	llvm::Type *getStringTy(uint64_t size) {
		return llvm::ArrayType::get(getCharTy(), size);
	}

	llvm::Type *getArrayTy(llvm::Type *ElementType, uint64_t NumElements) {
		return llvm::ArrayType::get(ElementType, NumElements);
	}

	llvm::Type *getStructTy(llvm::StringRef name) {
		return cur_module->getTypeByName(name);
	}

	llvm::Type *createStructTy(std::vector<llvm::Type *> types, llvm::StringRef name) {
		return llvm::StructType::create(*context, types, name);
	}
};


#endif //LLVM_TEST_CODE_GENERATOR_H
