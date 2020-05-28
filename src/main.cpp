#include "ast/ast.h"
#include "gen/code_generator.h"

#include <iostream>

extern int yyparse();
extern Program* ast_root;

int main() {
    int res = yyparse();
    std::cout << "parsing result: " << res << std::endl;
	std::cout << "========= Code Generation =========" << std::endl;
    CodeGenerator cg;
    cg.gencode(ast_root);
    return 0;
}