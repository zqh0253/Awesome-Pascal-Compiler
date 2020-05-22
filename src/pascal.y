%{
#include "ast/ast.h"
Program* ast_root;
%}

%union{
char chr
bool bool
int num
double real
Program* program
ProgramHeading* program_heading
ProgramBlock* program_block
ID* id
Statement* statement
StatementList* statement_list
}

%token REV_PROGRAM ID  OP_SEMICOLON

%start root

%type <program> program, root
%type <program_heading> program_heading
%type <program_block> program_block
%type <statement> statement
%type <statement_list> statement_list
 
%%

root : program {ast_root = $1; ast_root->prt();}

program : program_heading OP_SEMICOLON program_block OP_SEMICOLON {$$=new Program($1,$3);}

program_heading : REV_PROGRAM ID {$$=new ProgramHeading($2);}

program_block : statement_list {$=new program_block($1);}

statement_list : statement_list  OP_SEMICOLON statement{$$=$1;$$->add_statement($2);}
                |   statement                                       {$$=new StatementList($1);}

statement : ID {$$=new Statement($1);}

%%

