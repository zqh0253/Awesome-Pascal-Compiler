#ifndef LLVM_TEST_CODE_GENERATOR_H
#define LLVM_TEST_CODE_GENERATOR_H

#include "ast/ast.h"
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

	static std::string get_entry_name(std::string& s) {
		return s + "_entry";
	}


//	SemanticAnalyzer *top_sem() { return sem(block_stack.size()-1); }
//	SemanticAnalyzer *sem(int index) { return block_stack[index]->sa; }
//	SemanticAnalyzer *global_sem() { return sem(0); }
//
//	void set_local_variable();
//	llvm::Constant *get_constant();
};


#endif //LLVM_TEST_CODE_GENERATOR_H
