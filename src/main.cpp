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
    try {
	    cg.gencode(ast_root);
    } catch (sem::SemException e) {
		std::cout << e.what() << std::endl;
		cg.local_sem()->display(0);
    }
    return 0;
}