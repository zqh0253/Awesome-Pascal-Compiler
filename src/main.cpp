#include "ast/ast.h"
#include "sem/sem.h"
#include "gen/code_generator.h"

#include <iostream>

extern int yyparse();
extern Program* ast_root;

int main() {
    int res = yyparse();
    std::cout << "parsing result: " << res << std::endl;
    sem::Init();
	std::cout << "========= Code Generation =========" << std::endl;
    CodeGenerator cg;
    cg.gencode(ast_root);
    return 0;
}