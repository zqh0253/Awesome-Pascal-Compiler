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
IDDotted* idd;
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
SubProgram* subp;
SubProgramHead* subphead;
Parameters* param;
ParaDecList* paradl;
ParaTypeList* paratl;
Statement* stmt;
StatementList* stmtlst;
AssignStmt* assignstmt;
ProcStmt* procstmt;
CompoundStmt* compoundstmt;
IfStmt* ifstmt;
RepeatStmt* repeatstmt;
WhileStmt* whilestmt;
ForStmt* forstmt;
CaseStmt* casestmt;
GotoStmt* gotostmt;
Expression* texpression;
Expr* texpr;
Term* tterm;
ArgsList* argslist;
ExprList* exprlist;
SysProc* sysproc;
Factor* tfactor;
ElseClause* elseclause;
CaseExprList* caseexprlst;
CaseExpr* caseexpr;
}

%token REV_AND REV_ARRAY REV_BEGIN REV_BREAK REV_CASE REV_CONST REV_CONTINUE REV_DEFAULT REV_DIV REV_DO REV_DOWNTO 
%token REV_ELSE REV_END REV_EXIT REV_FILE REV_FOR REV_FORWARD REV_FUNCTION REV_GOTO REV_IF REV_IN REV_LABEL REV_MOD 
%token REV_NIL REV_NOT REV_OF REV_OR REV_PACKED REV_PROCEDURE REV_PROGRAM REV_RECORD REV_REPEAT REV_SET REV_SIZEOF 
%token REV_THEN REV_TO REV_TYPE REV_UNTIL REV_VAR REV_WHILE REV_WITH REV_XOR REV_READ REV_WRITE REV_WRITELN REV_PTR

%token OP_ADD OP_SUB OP_MOD OP_MUL OP_DIV OP_EQ OP_LT OP_GT OP_LBRAC OP_RBRAC OP_PERIOD OP_COMMA OP_COLON OP_SEMICOLON OP_AT 
%token OP_CARET OP_LPAREN OP_RPAREN OP_NE OP_LEQ OP_GEQ OP_ASSIGN OP_RANGE OP_ASTERISK OP_ADDR

%token TYPE_INT TYPE_REAL TYPE_CHAR TYPE_BOOL TYPE_STRING TYPE_POINTER

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

%type <idd> IDD;

%type <subp> sub_program;
%type <subphead> sub_program_head;
%type <param> parameters;
%type <paradl> para_dec_list;
%type <paratl> para_type_list;
%type <stmt> statement;
%type <stmtlst> statement_list;
%type <assignstmt> assign_stmt;
%type <procstmt> proc_stmt;
%type <compoundstmt> compound_stmt;
%type <ifstmt> if_stmt;
%type <repeatstmt> repeat_stmt;
%type <whilestmt> while_stmt;
%type <forstmt> for_stmt;
%type <casestmt> case_stmt;
%type <gotostmt> goto_stmt;
%type <texpression> expression;
%type <texpr> expr;
%type <tterm> term;
%type <argslist> args_list;
%type <exprlist> expr_list;
%type <sysproc> sys_proc;
%type <tfactor> factor;
%type <elseclause> else_clause;
%type <caseexprlst> case_expr_list;
%type <caseexpr> case_expr;
  
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
            | TYPE_POINTER simple_type {$$=new TypeDec($2); $$->ptr = 1;}

simple_type : sys_type {$$=new SimpleType($1);}
            | IDT {$$=new SimpleType($1);}
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

IDD : IDD OP_PERIOD IDT {$$=$1; $$->add($3);}
            | IDT {$$=new IDDotted(); $$->add($1);}

routine_part : routine_part sub_program {$$=$1; $$->add($2);}
            | sub_program               {$$=new RoutinePart(); $$->add($1);}
            |                           {$$=new RoutinePart(); $$->is_leaf = true;}

sub_program : sub_program_head OP_SEMICOLON routine OP_SEMICOLON {$$=new SubProgram($1,$3);}

sub_program_head : REV_FUNCTION IDT parameters OP_COLON simple_type {$$=new SubProgramHead($2,$3,$5);}
                 | REV_PROCEDURE IDT parameters {$$=new SubProgramHead($2,$3);}

parameters : OP_LPAREN para_dec_list OP_RPAREN  {$$=new Parameters($2);}
            | OP_LPAREN OP_RPAREN               {$$=new Parameters();}

para_dec_list : para_dec_list OP_SEMICOLON para_type_list {$$=$1; $$->add($3);}
            | para_type_list                              {$$=new ParaDecList(); $$->add($1);}

para_type_list : id_list OP_COLON simple_type {$$=new ParaTypeList($1,$3);}

routine_body : compound_stmt {$$=new RoutineBody($1);}

compound_stmt : REV_BEGIN statement_list REV_END {$$=new CompoundStmt($2);}

statement_list : statement_list statement OP_SEMICOLON  {$$=$1; $$->add($2);}
                |                                       {$$=new StatementList();}

statement :   INT OP_COLON assign_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON proc_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON compound_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON if_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON repeat_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON while_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON for_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON case_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | INT OP_COLON goto_stmt {$$=new Statement($3); $$->set_anchor($1);}
            | assign_stmt {$$=new Statement($1);}
            | proc_stmt {$$=new Statement($1);}
            | compound_stmt {$$=new Statement($1);}
            | if_stmt {$$=new Statement($1);}
            | repeat_stmt {$$=new Statement($1);}
            | while_stmt {$$=new Statement($1);}
            | for_stmt {$$=new Statement($1);}
            | case_stmt {$$=new Statement($1);}
            | goto_stmt {$$=new Statement($1);}

assign_stmt : IDD OP_ASSIGN expression  {$$=new AssignStmt($1, $3);}
            | IDD OP_LBRAC expression OP_RBRAC OP_ASSIGN expression {$$=new AssignStmt($1,$3,$6);}

proc_stmt   : IDT OP_LPAREN OP_RPAREN {$$=new ProcStmt($1);}
            | IDT OP_LPAREN args_list OP_RPAREN {$$=new ProcStmt($1, $3);}
            | sys_proc {$$=new ProcStmt($1);}
            | sys_proc OP_LPAREN expr_list OP_RPAREN {$$=new ProcStmt($1, $3);}
            | sys_proc OP_LPAREN factor OP_RPAREN {$$=new ProcStmt($1, $3);}

if_stmt     : REV_IF expression REV_THEN statement else_clause {$$=new IfStmt($2,$4,$5);}

else_clause : REV_ELSE statement    {$$=new ElseClause($2);}
            |                       {$$=new ElseClause();}

repeat_stmt : REV_REPEAT statement_list REV_UNTIL expression {$$=new RepeatStmt($2,$4);}

while_stmt  : REV_WHILE expression REV_DO statement {$$=new WhileStmt($2,$4);}

for_stmt    : REV_FOR IDD OP_ASSIGN expression REV_TO expression REV_DO statement {$$=new ForStmt($2,$4,$6,$8,ForStmt::TO);}
            | REV_FOR IDD OP_ASSIGN expression REV_DOWNTO expression REV_DO statement {$$=new ForStmt($2,$4,$6,$8,ForStmt::DOWNTO);}

case_stmt   : REV_CASE expression REV_OF case_expr_list REV_END {$$=new CaseStmt($2, $4);}

case_expr_list : case_expr_list case_expr {$$=$1; $$->add($2);}
                | case_expr               {$$=new CaseExprList(); $$->add($1);}

case_expr   : const_value OP_COLON statement OP_SEMICOLON   {$$=new CaseExpr($1, $3);}
            | IDD OP_COLON statement OP_SEMICOLON           {$$=new CaseExpr($1, $3);}

goto_stmt   : REV_GOTO INT  {$$=new GotoStmt($2);}

expr_list   : expr_list OP_COMMA expression {$$=$1; $$->add($3);}
            | expression                    {$$=new ExprList(); $$->add($1);}

args_list   : args_list OP_COMMA expression {$$=$1; $$->add($3);}
            | expression                    {$$=new ArgsList(); $$->add($1);}

expression  : expression OP_GEQ expr    {$$=new Expression($1, Expression::GE, $3);}
            | expression OP_GT expr     {$$=new Expression($1, Expression::GT, $3);}
            | expression OP_LEQ expr    {$$=new Expression($1, Expression::LE, $3);}
            | expression OP_LT expr     {$$=new Expression($1, Expression::LT, $3);}
            | expression OP_EQ expr     {$$=new Expression($1, Expression::EQ, $3);}
            | expression OP_NE expr     {$$=new Expression($1, Expression::NE, $3);}
            | expr                      {$$=new Expression($1);}

expr        : expr OP_ADD term          {$$=new Expr($1, Expr::PULS, $3);}
            | expr OP_SUB term          {$$=new Expr($1, Expr::MINUS, $3);}
            | expr REV_OR term          {$$=new Expr($1, Expr::OR, $3);}
            | term                      {$$=new Expr($1);}

term        : term OP_MUL factor        {$$=new Term($1, Term::MUL, $3);}
            | term REV_DIV factor        {$$=new Term($1, Term::DIV, $3);}
            | term OP_DIV factor        {$$=new Term($1, Term::DIV, $3);}
            | term OP_MOD factor        {$$=new Term($1, Term::MOD, $3);}
            | term REV_MOD factor        {$$=new Term($1, Term::MOD, $3);}
            | term REV_AND factor       {$$=new Term($1, Term::AND, $3);}
            | factor                    {$$=new Term($1);}

factor      : IDT OP_LPAREN args_list OP_RPAREN  {$$=new Factor($1,$3);}
            | IDT OP_LPAREN OP_RPAREN  {$$=new Factor($1);}
            | const_value               {$$=new Factor($1);}
            | OP_LPAREN expression OP_RPAREN    {$$=new Factor($2);}
            | REV_NOT factor            {$$=new Factor($2, Factor::NOT_FACTOR);}
            | OP_SUB factor             {$$=new Factor($2, Factor::MINUS_FACTOR);}
            | IDD OP_LBRAC expression OP_RBRAC  {$$=new Factor($1, $3);}
            | IDD                       {$$=new Factor($1);}
            | OP_ADDR IDD                 {$$=new Factor($2, Factor::ADDR);}
            | OP_ASTERISK IDD               {$$=new Factor($2, Factor::ASTERISK);}

sys_proc    : REV_READ                  {$$=new SysProc(SysProc::READ);}
            | REV_WRITE                  {$$=new SysProc(SysProc::WRITE);}
            | REV_WRITELN                 {$$=new SysProc(SysProc::WRITELN);}
%%

//int main() {
//    yyparse();
//    return 0;
//}

// int yyerror(char * s){ printf("%s\n",s); return 0; }