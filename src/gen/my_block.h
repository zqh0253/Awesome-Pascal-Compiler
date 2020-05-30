#ifndef LLVM_TEST_MY_BLOCK_H
#define LLVM_TEST_MY_BLOCK_H

#include "llvm.h"
#include "sem/sem.h"

class MyBlock {
public:
	llvm::BasicBlock *bb;
	llvm::BasicBlock *cbb;
	sem::SemanticAnalyzer *sa;
	MyBlock(llvm::BasicBlock *bb, sem::SemanticAnalyzer *sa) {
		this->bb = this->cbb = bb;
		this->sa = sa;
	}
};


#endif //LLVM_TEST_MY_BLOCK_H
