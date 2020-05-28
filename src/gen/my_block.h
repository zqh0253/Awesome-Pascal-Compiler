#ifndef LLVM_TEST_MY_BLOCK_H
#define LLVM_TEST_MY_BLOCK_H

#include "llvm.h"
#include "sem/sem.h"

class MyBlock {
public:
	llvm::BasicBlock *block;
	sem::SemanticAnalyzer *sa;
	MyBlock() {
		block = nullptr;
		sa = nullptr;
	}
	MyBlock(llvm::BasicBlock *block, sem::SemanticAnalyzer *sa) {
		this->block = block;
		this->sa = sa;
	}

};


#endif //LLVM_TEST_MY_BLOCK_H
