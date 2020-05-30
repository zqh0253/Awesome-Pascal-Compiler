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

	static std::string get_entry_name(const std::string& s) {
		return s + "_entry";
	}

	std::string to_global_name(const std::string &name) {
		return local_sem()->name + "_" + name;
	}

	// block
	void push_block(MyBlock *block) {
		if (block) {
			block->sa->cg = this;
			block->sa->level = this->block_stack.size();
			block_stack.push_back(block);
			ir_builder->SetInsertPoint(block->bb);
		}
	}
	void push_block(llvm::BasicBlock *bb, sem::SemanticAnalyzer *sa) {
		push_block(new MyBlock(bb, sa));
	}
	void push_block(llvm::BasicBlock *bb, const std::string &name) {
		push_block(new MyBlock(bb, new sem::SemanticAnalyzer(to_global_name(name))));
	}
	MyBlock *pop_block() {
		MyBlock *top = local_block();
		block_stack.pop_back();
		ir_builder->SetInsertPoint(local_bb());
		return top;
	}
	sem::SemanticAnalyzer *local_sem() { return local_block()->sa; }
	sem::SemanticAnalyzer *global_sem() { return global_block()->sa; }
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
	llvm::Module * get_module(const std::string &name) {
		llvm::Module *ret = nullptr;
		if (modules.count(name)) {
			ret = modules[name];
		}
		return ret;
	}

	// sem
	sem::SemType *get_var_sem_type(const std::string &name);
	sem::SemType *get_sem_type(const std::string &name);
	sem::FuncInfo *get_sem_func(const std::string &name);

	// constant and type
	llvm::Type *get_var_llvm_type(const std::string &name);
	llvm::Constant *to_llvm_constant(ConstValue *c);
	llvm::Type *to_llvm_type(sem::SemType *type);

	llvm::Type *getIntTy() {
		return ir_builder->getInt32Ty();
	}

	llvm::Type *getVoidTy() {
		return ir_builder->getVoidTy();
	}

	llvm::Type *getCharTy() {
		return ir_builder->getInt8Ty();
	}

	llvm::Type *getRealTy() {
		return ir_builder->getDoubleTy();
	}

	llvm::Type *getBoolTy() {
		return ir_builder->getInt1Ty();
	}

	llvm::Type *getStringTy(uint64_t size) {
		return llvm::ArrayType::get(getCharTy(), size);
	}

	llvm::Type *getArrayTy(llvm::Type *ElementType, uint64_t NumElements) {
		return llvm::ArrayType::get(ElementType, NumElements);
	}

	llvm::StructType *getStructTy(const std::string &name) {
		return cur_module->getTypeByName(name);
	}

	llvm::Type *createStructTy(std::vector<llvm::Type *> &types, const std::string &name) {
		return llvm::StructType::create(*context, types, name);
	}

	// function
	llvm::Function *create_llvm_function(const std::string &name, sem::FuncInfo *func) {
		std::vector<llvm::Type*> arg_list;
		for (auto t: func->types) {
			arg_list.push_back(to_llvm_type(t.second));
		}
		if (func->ret) arg_list.pop_back();
		llvm::FunctionType *func_type = llvm::FunctionType::get(to_llvm_type(func->ret), arg_list, false);
		llvm::Function *llvm_func = llvm::Function::Create(func_type, llvm::GlobalValue::InternalLinkage,
		                                                   to_global_name(name), cur_module);
		llvm::BasicBlock *bb = llvm::BasicBlock::Create(*context, "start", llvm_func);
		sem::SemanticAnalyzer *sa = new sem::SemanticAnalyzer(to_global_name(name), func->types);
		push_block(bb, sa);
		for (int i = 0; i < func->types.size(); i++) {
			auto it = func->types[i];
			alloc_local_variable(to_llvm_type(it.second), it.first);
			if (!func->ret || i < func->types.size()-1)
				store_local_variable(it.first, llvm_func->getArg(i));
		}
		return llvm_func;
	}

	llvm::Function *get_llvm_function(const std::string &name) {
		return cur_module->getFunction(to_global_name(name));
	}

	llvm::Value *make_call(const std::string &name, std::vector<llvm::Value*> args) {
		llvm::Function *func = get_llvm_function(name);
		if (name == "printf") {
			func = cur_module->getFunction(name);
			args[0] = ir_builder->CreateCast(llvm::Instruction::CastOps::BitCast,
					args[0], ir_builder->getInt8PtrTy());
		}
		return ir_builder->CreateCall(func, args);
	}

	void register_printf() {
		std::vector<llvm::Type*> printf_arg_types; // 这里是参数表
		printf_arg_types.push_back(llvm::Type::getInt8PtrTy(cur_module->getContext()));

		llvm::FunctionType* printf_type =
				llvm::FunctionType::get(
						llvm::Type::getInt32Ty(cur_module->getContext()), printf_arg_types, true);
		// 这里的true表示后面接不定参数
		llvm::Function *func = llvm::Function::Create(
				printf_type, llvm::Function::ExternalLinkage,
				llvm::Twine("printf"),
				cur_module
		);
		func->setCallingConv(llvm::CallingConv::C); // 一定注意调用方式的正确性
		local_sem()->funcs["printf"] = nullptr;
	}

	// variable
	llvm::Instruction *alloc_local_variable(llvm::Type *type, const std::string &name);
	llvm::Value *get_local_variable(const std::string &name);
	llvm::Instruction *store_local_variable(const std::string &name, llvm::Value *val);
	llvm::Value *load_variable(llvm::Value *ptr);
	llvm::Value *load_local_variable(const std::string &name);
	llvm::Value *get_record_member(sem::RecordMember *rm);
	llvm::Value *get_record_member(sem::RecordMember *rm, llvm::Value *index);
	llvm::Value *get_record_member(sem::RecordMember *rm, int index);
//	llvm::Value *get_array_el(sem::RecordMember *rm);
};


#endif //LLVM_TEST_CODE_GENERATOR_H
