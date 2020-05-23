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
float real;
char* str;
Program* program;
ProgramHeading* programh;
Routine* rout;
ID* idt;
IDList* idl;
RoutineHead* routineh;
RoutineBody* routineb;
LabelPart* labelp;
ConstPart* constp;
TypePart* typep;
VarPart* varp;
RoutinePart* routinep;
ConstExpr* conste;
ConstExprList* constel;
ConstValue* constv;
TypeDecList* tdl;
TypeDec* typedec;
TypeDef* typedefi;
SysType* syst;
RangeType* ranget;
ArrayType* arrayt;
RecordType* recordt;
SimpleType* simplet;
VarDecList* vdl;
VarDec* vard;
}

%token REV_AND REV_ARRAY REV_BEGIN REV_BREAK REV_CASE REV_CONST REV_CONTINUE REV_DEFAULT REV_DIV REV_DO REV_DOWNTO 
%token REV_ELSE REV_END REV_EXIT REV_FILE REV_FOR REV_FORWARD REV_FUNCTION REV_GOTO REV_IF REV_IN REV_LABEL REV_MOD 
%token REV_NIL REV_NOT REV_OF REV_OR REV_PACKED REV_PROCEDURE REV_PROGRAM REV_RECORD REV_REPEAT REV_SET REV_SIZEOF 
%token REV_THEN REV_TO REV_TYPE REV_UNTIL REV_VAR REV_WHILE REV_WITH REV_XOR 

%token OP_ADD OP_SUB OP_MUL OP_DIV OP_EQ OP_LT OP_GT OP_LBRAC OP_RBRAC OP_PERIOD OP_COMMA OP_COLON OP_SEMICOLON OP_AT 
%token OP_CARET OP_LPAREN OP_RPAREN OP_NE OP_LEQ OP_GEQ OP_ASSIGN OP_RANGE 

%token TYPE_INT TYPE_REAL TYPE_CHAR TYPE_BOOL TYPE_STRING 

%token BOOL_TRUE BOOL_FALSE IDT

%token SIGN INT REAL  CHAR ESC_CHAR  STR COMMENT

%start root

%type <chr> OP_SEMICOLON OP_PERIOD
%type <idt> IDT
%type <idl> id_list
%type <num> INT
%type <chr> CHAR
%type <real> REAL
%type <str> STR
%type <program> program root
%type <programh> program_heading
%type <rout> routine
%type <routineh> routine_head
%type <routineb> routine_body
%type <labelp> label_part
%type <constp> const_part
%type <typep> type_part
%type <varp> var_part
%type <routinep> routine_part
%type <conste> const_expr
%type <constel> const_expr_list
%type <constv> const_value
%type <tdl> type_dec_list
%type <typedec> type_dec
%type <typedefi> type_def
%type <syst> sys_type
%type <ranget> range_type
%type <arrayt> array_type
%type <recordt> record_type
%type <simplet> simple_type
%type <vdl> var_dec_list
%type <vard> var_dec
  
%%

root : program {ast_root = $1; ast_root->prt(0);}

program : program_heading routine OP_PERIOD  {$$=new Program($1,$2);}

program_heading : REV_PROGRAM IDT OP_SEMICOLON {$$=new ProgramHeading($2);}

routine : routine_head routine_body {$$=new Routine($1, $2);}

routine_head : label_part const_part type_part var_part routine_part {$$=new RoutineHead($1,$2,$3,$4,$5);}

label_part : {$$=new LabelPart();}

const_part : REV_CONST const_expr_list {$$=new ConstPart($2);}
            |                          {$$=new ConstPart();}

const_expr_list : const_expr_list const_expr {$$=$1; $$->add($2);}
                | const_expr                 {$$=new ConstExprList(); $$->add($1);}

const_expr : IDT OP_EQ const_value OP_SEMICOLON {$$=new ConstExpr($1,$3);}

const_value : INT {$$=new ConstValue($1);}
            | REAL {$$=new ConstValue($1);}
            | CHAR {$$=new ConstValue($1);}
            | STR {std::string tmp = $1; $$=new ConstValue(tmp);}
            | BOOL_TRUE {$$=new ConstValue(ConstValue::TRUE);}
            | BOOL_FALSE {$$=new ConstValue(ConstValue::FALSE);}

type_part : REV_TYPE type_dec_list {$$=new TypePart($2);}
            |                      {$$=new TypePart();}

type_dec_list : type_dec_list type_def {$$=$1; $$->add($2);}
            | type_def                 {$$=new TypeDecList(); $$->add($1);}

type_def : IDT OP_EQ type_dec OP_SEMICOLON {$$=new TypeDef($1,$3);}

type_dec : simple_type {$$=new TypeDec($1);}
            | array_type {$$=new TypeDec($1);}
            | record_type {$$=new TypeDec($1);}

simple_type : sys_type {$$=new SimpleType($1);}
            | IDT {$$=new SimpleType($1);}
            | OP_LPAREN id_list OP_RPAREN {$$=new SimpleType($2);}
            | range_type {$$=new SimpleType($1);}

sys_type : TYPE_BOOL {$$=new SysType(SysType::BOOLEAN);}
            | TYPE_CHAR {$$=new SysType(SysType::CHAR);}
            | TYPE_INT {$$=new SysType(SysType::INTEGER);}
            | TYPE_REAL {$$=new SysType(SysType::REAL);}
            | TYPE_STRING {$$=new SysType(SysType::STRING);}

range_type : const_value OP_RANGE const_value {$$=new RangeType($1,$3,false,false);}
            | OP_SUB const_value OP_RANGE const_value {$$=new RangeType($2,$4, true,false);}
            | OP_SUB const_value OP_RANGE OP_SUB const_value {$$=new RangeType($2,$5, true,true);}
            | const_value OP_RANGE OP_SUB const_value {$$=new RangeType($1,$4, false,true);}
            | IDT OP_RANGE IDT {$$=new RangeType($1, $3);}

array_type : REV_ARRAY OP_LBRAC simple_type OP_RBRAC REV_OF type_dec {$$=new ArrayType($3,$6);}

record_type : REV_RECORD var_dec_list REV_END {$$=new RecordType($2);}

var_part : REV_VAR var_dec_list {$$=new VarPart($2);}
            |                   {$$=new VarPart();}

var_dec_list : var_dec_list var_dec {$$=$1; $$->add($2);}
            | var_dec {$$=new VarDecList(); $$->add($1);}

var_dec : id_list OP_COLON type_dec OP_SEMICOLON {$$=new VarDec($1, $3);}

id_list : id_list OP_COMMA IDT {$$=$1; $$->add($3);}
            | IDT {$$=new IDList(); $$->add($1);}

routine_part : {$$=new RoutinePart();}

routine_body : {$$=new RoutineBody();}
%%

int main() {
    yyparse();
    return 0; 
}

// int yyerror(char * s){ printf("%s\n",s); return 0; }