#ifndef LLVM_TEST_MY_BLOCK_H
#define LLVM_TEST_MY_BLOCK_H

#include "llvm.h"

class SemanticAnalyzer;

class MyBlock {
public:
	llvm::BasicBlock *block;
	SemanticAnalyzer *sa;
	MyBlock() {}
};


#endif //LLVM_TEST_MY_BLOCK_H
