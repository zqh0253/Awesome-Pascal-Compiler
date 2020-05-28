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
	llvm::Module *module = nullptr;
	llvm::LLVMContext *context = nullptr;
	llvm::IRBuilder<> *ir_builder = nullptr;

	CodeGenerator() = default;

	void gencode(Node *root);
	void pre_gencode(Node *root);

	static std::string get_entry_name(std::string& s) {
		return s + "_entry";
	}

	sem::SemanticAnalyzer *top_sem() { return top_block()->sa; }
	MyBlock *top_block() { return get_block(block_stack.size()-1); }
	MyBlock *get_block(int index) { return block_stack[index]; }
	MyBlock *global_block() { return get_block(0); }

//	void set_local_variable();
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
		return module->getTypeByName(name);
	}

	llvm::Type *createStructTy(std::vector<llvm::Type *> types, llvm::StringRef name) {
		return llvm::StructType::create(*context, types, name);
	}
};


#endif //LLVM_TEST_CODE_GENERATOR_H
