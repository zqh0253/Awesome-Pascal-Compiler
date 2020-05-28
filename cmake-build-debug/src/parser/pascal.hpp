/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PASCAL_HPP_INCLUDED
# define YY_YY_PASCAL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"

#define MAX_STR_LEN 1024

#line 52 "pascal.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    REV_AND = 258,
    REV_ARRAY = 259,
    REV_BEGIN = 260,
    REV_BREAK = 261,
    REV_CASE = 262,
    REV_CONST = 263,
    REV_CONTINUE = 264,
    REV_DEFAULT = 265,
    REV_DIV = 266,
    REV_DO = 267,
    REV_DOWNTO = 268,
    REV_ELSE = 269,
    REV_END = 270,
    REV_EXIT = 271,
    REV_FILE = 272,
    REV_FOR = 273,
    REV_FORWARD = 274,
    REV_FUNCTION = 275,
    REV_GOTO = 276,
    REV_IF = 277,
    REV_IN = 278,
    REV_LABEL = 279,
    REV_MOD = 280,
    REV_NIL = 281,
    REV_NOT = 282,
    REV_OF = 283,
    REV_OR = 284,
    REV_PACKED = 285,
    REV_PROCEDURE = 286,
    REV_PROGRAM = 287,
    REV_RECORD = 288,
    REV_REPEAT = 289,
    REV_SET = 290,
    REV_SIZEOF = 291,
    REV_THEN = 292,
    REV_TO = 293,
    REV_TYPE = 294,
    REV_UNTIL = 295,
    REV_VAR = 296,
    REV_WHILE = 297,
    REV_WITH = 298,
    REV_XOR = 299,
    REV_READ = 300,
    REV_WRITE = 301,
    REV_WRITELN = 302,
    OP_ADD = 303,
    OP_SUB = 304,
    OP_MOD = 305,
    OP_MUL = 306,
    OP_DIV = 307,
    OP_EQ = 308,
    OP_LT = 309,
    OP_GT = 310,
    OP_LBRAC = 311,
    OP_RBRAC = 312,
    OP_PERIOD = 313,
    OP_COMMA = 314,
    OP_COLON = 315,
    OP_SEMICOLON = 316,
    OP_AT = 317,
    OP_CARET = 318,
    OP_LPAREN = 319,
    OP_RPAREN = 320,
    OP_NE = 321,
    OP_LEQ = 322,
    OP_GEQ = 323,
    OP_ASSIGN = 324,
    OP_RANGE = 325,
    TYPE_INT = 326,
    TYPE_REAL = 327,
    TYPE_CHAR = 328,
    TYPE_BOOL = 329,
    TYPE_STRING = 330,
    BOOL_TRUE = 331,
    BOOL_FALSE = 332,
    IDT = 333,
    SIGN = 334,
    INT = 335,
    REAL = 336,
    CHAR = 337,
    ESC_CHAR = 338,
    STR = 339,
    COMMENT = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"

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

#line 207 "pascal.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PASCAL_HPP_INCLUDED  */
