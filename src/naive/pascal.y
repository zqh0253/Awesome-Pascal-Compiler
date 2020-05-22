%locations

%code requires {
#define MAX_STR_LEN 1024
}

%{
#include "ast/ast.h"

Program* ast_root;

extern int yylex();
extern void yyerror(const char * s);
%}

%union{
char chr;
int num;
double real;
Program* program;
ProgramHeading* ph;
ProgramBlock* pb;
ID* idt;
Statement* stm;
StatementList* stml;
char *str;
}

%token REV_PROGRAM IDT  OP_SEMICOLON

%start root

%type <chr> OP_SEMICOLON
%type <idt> IDT
%type <program> program root
%type <ph> program_heading
%type <pb> program_block
%type <stm> statement
%type <stml> statement_list
 
%%

root : program {ast_root = $1; ast_root->prt(0);}

program : program_heading OP_SEMICOLON program_block OP_SEMICOLON {$$=new Program($1,$3);}

program_heading : REV_PROGRAM IDT {printf("ph\n");$$=new ProgramHeading($2);}

program_block : statement_list {$$=new ProgramBlock($1);}

statement_list : statement_list statement OP_SEMICOLON {$$=$1;$$->add_statement($2);}
                |                                       {$$=new StatementList();}

statement : IDT {$$=new Statement($1);}

%%

int main() {
    yyparse();
    return 0; 
}

// int yyerror(char * s){ printf("%s\n",s); return 0; }