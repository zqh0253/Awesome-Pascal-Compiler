/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 3 "pascal.y"

#define MAX_STR_LEN 1024

#line 53 "pascal.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    REV_AND = 258,                 /* REV_AND  */
    REV_ARRAY = 259,               /* REV_ARRAY  */
    REV_BEGIN = 260,               /* REV_BEGIN  */
    REV_BREAK = 261,               /* REV_BREAK  */
    REV_CASE = 262,                /* REV_CASE  */
    REV_CONST = 263,               /* REV_CONST  */
    REV_CONTINUE = 264,            /* REV_CONTINUE  */
    REV_DEFAULT = 265,             /* REV_DEFAULT  */
    REV_DIV = 266,                 /* REV_DIV  */
    REV_DO = 267,                  /* REV_DO  */
    REV_DOWNTO = 268,              /* REV_DOWNTO  */
    REV_ELSE = 269,                /* REV_ELSE  */
    REV_END = 270,                 /* REV_END  */
    REV_EXIT = 271,                /* REV_EXIT  */
    REV_FILE = 272,                /* REV_FILE  */
    REV_FOR = 273,                 /* REV_FOR  */
    REV_FORWARD = 274,             /* REV_FORWARD  */
    REV_FUNCTION = 275,            /* REV_FUNCTION  */
    REV_GOTO = 276,                /* REV_GOTO  */
    REV_IF = 277,                  /* REV_IF  */
    REV_IN = 278,                  /* REV_IN  */
    REV_LABEL = 279,               /* REV_LABEL  */
    REV_MOD = 280,                 /* REV_MOD  */
    REV_NIL = 281,                 /* REV_NIL  */
    REV_NOT = 282,                 /* REV_NOT  */
    REV_OF = 283,                  /* REV_OF  */
    REV_OR = 284,                  /* REV_OR  */
    REV_PACKED = 285,              /* REV_PACKED  */
    REV_PROCEDURE = 286,           /* REV_PROCEDURE  */
    REV_PROGRAM = 287,             /* REV_PROGRAM  */
    REV_RECORD = 288,              /* REV_RECORD  */
    REV_REPEAT = 289,              /* REV_REPEAT  */
    REV_SET = 290,                 /* REV_SET  */
    REV_SIZEOF = 291,              /* REV_SIZEOF  */
    REV_THEN = 292,                /* REV_THEN  */
    REV_TO = 293,                  /* REV_TO  */
    REV_TYPE = 294,                /* REV_TYPE  */
    REV_UNTIL = 295,               /* REV_UNTIL  */
    REV_VAR = 296,                 /* REV_VAR  */
    REV_WHILE = 297,               /* REV_WHILE  */
    REV_WITH = 298,                /* REV_WITH  */
    REV_XOR = 299,                 /* REV_XOR  */
    OP_ADD = 300,                  /* OP_ADD  */
    OP_SUB = 301,                  /* OP_SUB  */
    OP_MUL = 302,                  /* OP_MUL  */
    OP_DIV = 303,                  /* OP_DIV  */
    OP_EQ = 304,                   /* OP_EQ  */
    OP_LT = 305,                   /* OP_LT  */
    OP_GT = 306,                   /* OP_GT  */
    OP_LBRAC = 307,                /* OP_LBRAC  */
    OP_RBRAC = 308,                /* OP_RBRAC  */
    OP_PERIOD = 309,               /* OP_PERIOD  */
    OP_COMMA = 310,                /* OP_COMMA  */
    OP_COLON = 311,                /* OP_COLON  */
    OP_SEMICOLON = 312,            /* OP_SEMICOLON  */
    OP_AT = 313,                   /* OP_AT  */
    OP_CARET = 314,                /* OP_CARET  */
    OP_LPAREN = 315,               /* OP_LPAREN  */
    OP_RPAREN = 316,               /* OP_RPAREN  */
    OP_NE = 317,                   /* OP_NE  */
    OP_LEQ = 318,                  /* OP_LEQ  */
    OP_GEQ = 319,                  /* OP_GEQ  */
    OP_ASSIGN = 320,               /* OP_ASSIGN  */
    OP_RANGE = 321,                /* OP_RANGE  */
    TYPE_INT = 322,                /* TYPE_INT  */
    TYPE_REAL = 323,               /* TYPE_REAL  */
    TYPE_CHAR = 324,               /* TYPE_CHAR  */
    TYPE_BOOL = 325,               /* TYPE_BOOL  */
    TYPE_STRING = 326,             /* TYPE_STRING  */
    BOOL_TRUE = 327,               /* BOOL_TRUE  */
    BOOL_FALSE = 328,              /* BOOL_FALSE  */
    IDT = 329,                     /* IDT  */
    SIGN = 330,                    /* SIGN  */
    INT = 331,                     /* INT  */
    REAL = 332,                    /* REAL  */
    CHAR = 333,                    /* CHAR  */
    ESC_CHAR = 334,                /* ESC_CHAR  */
    STR = 335,                     /* STR  */
    COMMENT = 336                  /* COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "pascal.y"

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

#line 183 "pascal.hpp"

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
