#ifndef LLVM_TEST_MY_BLOCK_H
#define LLVM_TEST_MY_BLOCK_H

#include "llvm.h"
#include "sem/sem.h"

class MyBlock {
public:
	llvm::BasicBlock *bb;
	sem::SemanticAnalyzer *sa;
	MyBlock() {
		bb = nullptr;
		sa = nullptr;
	}
	MyBlock(llvm::BasicBlock *bb, sem::SemanticAnalyzer *sa) {
		this->bb = bb;
		this->sa = sa;
	}

};


#endif //LLVM_TEST_MY_BLOCK_H
