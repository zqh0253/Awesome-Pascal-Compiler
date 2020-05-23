/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "pascal.y"

#include "ast/ast.h"

Program* ast_root;

extern int yylex();
extern void yyerror(const char * s);

#line 80 "pascal.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 119 "pascal.cpp"

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
    REV_READ = 300,                /* REV_READ  */
    REV_WRITE = 301,               /* REV_WRITE  */
    REV_WRITELN = 302,             /* REV_WRITELN  */
    OP_ADD = 303,                  /* OP_ADD  */
    OP_SUB = 304,                  /* OP_SUB  */
    OP_MOD = 305,                  /* OP_MOD  */
    OP_MUL = 306,                  /* OP_MUL  */
    OP_DIV = 307,                  /* OP_DIV  */
    OP_EQ = 308,                   /* OP_EQ  */
    OP_LT = 309,                   /* OP_LT  */
    OP_GT = 310,                   /* OP_GT  */
    OP_LBRAC = 311,                /* OP_LBRAC  */
    OP_RBRAC = 312,                /* OP_RBRAC  */
    OP_PERIOD = 313,               /* OP_PERIOD  */
    OP_COMMA = 314,                /* OP_COMMA  */
    OP_COLON = 315,                /* OP_COLON  */
    OP_SEMICOLON = 316,            /* OP_SEMICOLON  */
    OP_AT = 317,                   /* OP_AT  */
    OP_CARET = 318,                /* OP_CARET  */
    OP_LPAREN = 319,               /* OP_LPAREN  */
    OP_RPAREN = 320,               /* OP_RPAREN  */
    OP_NE = 321,                   /* OP_NE  */
    OP_LEQ = 322,                  /* OP_LEQ  */
    OP_GEQ = 323,                  /* OP_GEQ  */
    OP_ASSIGN = 324,               /* OP_ASSIGN  */
    OP_RANGE = 325,                /* OP_RANGE  */
    TYPE_INT = 326,                /* TYPE_INT  */
    TYPE_REAL = 327,               /* TYPE_REAL  */
    TYPE_CHAR = 328,               /* TYPE_CHAR  */
    TYPE_BOOL = 329,               /* TYPE_BOOL  */
    TYPE_STRING = 330,             /* TYPE_STRING  */
    BOOL_TRUE = 331,               /* BOOL_TRUE  */
    BOOL_FALSE = 332,              /* BOOL_FALSE  */
    IDT = 333,                     /* IDT  */
    SIGN = 334,                    /* SIGN  */
    INT = 335,                     /* INT  */
    REAL = 336,                    /* REAL  */
    CHAR = 337,                    /* CHAR  */
    ESC_CHAR = 338,                /* ESC_CHAR  */
    STR = 339,                     /* STR  */
    COMMENT = 340                  /* COMMENT  */
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

#line 279 "pascal.cpp"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_REV_AND = 3,                    /* REV_AND  */
  YYSYMBOL_REV_ARRAY = 4,                  /* REV_ARRAY  */
  YYSYMBOL_REV_BEGIN = 5,                  /* REV_BEGIN  */
  YYSYMBOL_REV_BREAK = 6,                  /* REV_BREAK  */
  YYSYMBOL_REV_CASE = 7,                   /* REV_CASE  */
  YYSYMBOL_REV_CONST = 8,                  /* REV_CONST  */
  YYSYMBOL_REV_CONTINUE = 9,               /* REV_CONTINUE  */
  YYSYMBOL_REV_DEFAULT = 10,               /* REV_DEFAULT  */
  YYSYMBOL_REV_DIV = 11,                   /* REV_DIV  */
  YYSYMBOL_REV_DO = 12,                    /* REV_DO  */
  YYSYMBOL_REV_DOWNTO = 13,                /* REV_DOWNTO  */
  YYSYMBOL_REV_ELSE = 14,                  /* REV_ELSE  */
  YYSYMBOL_REV_END = 15,                   /* REV_END  */
  YYSYMBOL_REV_EXIT = 16,                  /* REV_EXIT  */
  YYSYMBOL_REV_FILE = 17,                  /* REV_FILE  */
  YYSYMBOL_REV_FOR = 18,                   /* REV_FOR  */
  YYSYMBOL_REV_FORWARD = 19,               /* REV_FORWARD  */
  YYSYMBOL_REV_FUNCTION = 20,              /* REV_FUNCTION  */
  YYSYMBOL_REV_GOTO = 21,                  /* REV_GOTO  */
  YYSYMBOL_REV_IF = 22,                    /* REV_IF  */
  YYSYMBOL_REV_IN = 23,                    /* REV_IN  */
  YYSYMBOL_REV_LABEL = 24,                 /* REV_LABEL  */
  YYSYMBOL_REV_MOD = 25,                   /* REV_MOD  */
  YYSYMBOL_REV_NIL = 26,                   /* REV_NIL  */
  YYSYMBOL_REV_NOT = 27,                   /* REV_NOT  */
  YYSYMBOL_REV_OF = 28,                    /* REV_OF  */
  YYSYMBOL_REV_OR = 29,                    /* REV_OR  */
  YYSYMBOL_REV_PACKED = 30,                /* REV_PACKED  */
  YYSYMBOL_REV_PROCEDURE = 31,             /* REV_PROCEDURE  */
  YYSYMBOL_REV_PROGRAM = 32,               /* REV_PROGRAM  */
  YYSYMBOL_REV_RECORD = 33,                /* REV_RECORD  */
  YYSYMBOL_REV_REPEAT = 34,                /* REV_REPEAT  */
  YYSYMBOL_REV_SET = 35,                   /* REV_SET  */
  YYSYMBOL_REV_SIZEOF = 36,                /* REV_SIZEOF  */
  YYSYMBOL_REV_THEN = 37,                  /* REV_THEN  */
  YYSYMBOL_REV_TO = 38,                    /* REV_TO  */
  YYSYMBOL_REV_TYPE = 39,                  /* REV_TYPE  */
  YYSYMBOL_REV_UNTIL = 40,                 /* REV_UNTIL  */
  YYSYMBOL_REV_VAR = 41,                   /* REV_VAR  */
  YYSYMBOL_REV_WHILE = 42,                 /* REV_WHILE  */
  YYSYMBOL_REV_WITH = 43,                  /* REV_WITH  */
  YYSYMBOL_REV_XOR = 44,                   /* REV_XOR  */
  YYSYMBOL_REV_READ = 45,                  /* REV_READ  */
  YYSYMBOL_REV_WRITE = 46,                 /* REV_WRITE  */
  YYSYMBOL_REV_WRITELN = 47,               /* REV_WRITELN  */
  YYSYMBOL_OP_ADD = 48,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 49,                    /* OP_SUB  */
  YYSYMBOL_OP_MOD = 50,                    /* OP_MOD  */
  YYSYMBOL_OP_MUL = 51,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 52,                    /* OP_DIV  */
  YYSYMBOL_OP_EQ = 53,                     /* OP_EQ  */
  YYSYMBOL_OP_LT = 54,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 55,                     /* OP_GT  */
  YYSYMBOL_OP_LBRAC = 56,                  /* OP_LBRAC  */
  YYSYMBOL_OP_RBRAC = 57,                  /* OP_RBRAC  */
  YYSYMBOL_OP_PERIOD = 58,                 /* OP_PERIOD  */
  YYSYMBOL_OP_COMMA = 59,                  /* OP_COMMA  */
  YYSYMBOL_OP_COLON = 60,                  /* OP_COLON  */
  YYSYMBOL_OP_SEMICOLON = 61,              /* OP_SEMICOLON  */
  YYSYMBOL_OP_AT = 62,                     /* OP_AT  */
  YYSYMBOL_OP_CARET = 63,                  /* OP_CARET  */
  YYSYMBOL_OP_LPAREN = 64,                 /* OP_LPAREN  */
  YYSYMBOL_OP_RPAREN = 65,                 /* OP_RPAREN  */
  YYSYMBOL_OP_NE = 66,                     /* OP_NE  */
  YYSYMBOL_OP_LEQ = 67,                    /* OP_LEQ  */
  YYSYMBOL_OP_GEQ = 68,                    /* OP_GEQ  */
  YYSYMBOL_OP_ASSIGN = 69,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_RANGE = 70,                  /* OP_RANGE  */
  YYSYMBOL_TYPE_INT = 71,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_REAL = 72,                 /* TYPE_REAL  */
  YYSYMBOL_TYPE_CHAR = 73,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_BOOL = 74,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 75,               /* TYPE_STRING  */
  YYSYMBOL_BOOL_TRUE = 76,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 77,                /* BOOL_FALSE  */
  YYSYMBOL_IDT = 78,                       /* IDT  */
  YYSYMBOL_SIGN = 79,                      /* SIGN  */
  YYSYMBOL_INT = 80,                       /* INT  */
  YYSYMBOL_REAL = 81,                      /* REAL  */
  YYSYMBOL_CHAR = 82,                      /* CHAR  */
  YYSYMBOL_ESC_CHAR = 83,                  /* ESC_CHAR  */
  YYSYMBOL_STR = 84,                       /* STR  */
  YYSYMBOL_COMMENT = 85,                   /* COMMENT  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_root = 87,                      /* root  */
  YYSYMBOL_program = 88,                   /* program  */
  YYSYMBOL_program_heading = 89,           /* program_heading  */
  YYSYMBOL_routine = 90,                   /* routine  */
  YYSYMBOL_routine_head = 91,              /* routine_head  */
  YYSYMBOL_label_part = 92,                /* label_part  */
  YYSYMBOL_const_part = 93,                /* const_part  */
  YYSYMBOL_const_expr_list = 94,           /* const_expr_list  */
  YYSYMBOL_const_expr = 95,                /* const_expr  */
  YYSYMBOL_const_value = 96,               /* const_value  */
  YYSYMBOL_type_part = 97,                 /* type_part  */
  YYSYMBOL_type_dec_list = 98,             /* type_dec_list  */
  YYSYMBOL_type_def = 99,                  /* type_def  */
  YYSYMBOL_type_dec = 100,                 /* type_dec  */
  YYSYMBOL_simple_type = 101,              /* simple_type  */
  YYSYMBOL_sys_type = 102,                 /* sys_type  */
  YYSYMBOL_range_type = 103,               /* range_type  */
  YYSYMBOL_array_type = 104,               /* array_type  */
  YYSYMBOL_record_type = 105,              /* record_type  */
  YYSYMBOL_var_part = 106,                 /* var_part  */
  YYSYMBOL_var_dec_list = 107,             /* var_dec_list  */
  YYSYMBOL_var_dec = 108,                  /* var_dec  */
  YYSYMBOL_id_list = 109,                  /* id_list  */
  YYSYMBOL_IDD = 110,                      /* IDD  */
  YYSYMBOL_routine_part = 111,             /* routine_part  */
  YYSYMBOL_sub_program = 112,              /* sub_program  */
  YYSYMBOL_parameters = 113,               /* parameters  */
  YYSYMBOL_para_dec_list = 114,            /* para_dec_list  */
  YYSYMBOL_para_type_list = 115,           /* para_type_list  */
  YYSYMBOL_routine_body = 116,             /* routine_body  */
  YYSYMBOL_compound_stmt = 117,            /* compound_stmt  */
  YYSYMBOL_statement_list = 118,           /* statement_list  */
  YYSYMBOL_statement = 119,                /* statement  */
  YYSYMBOL_assign_stmt = 120,              /* assign_stmt  */
  YYSYMBOL_proc_stmt = 121,                /* proc_stmt  */
  YYSYMBOL_if_stmt = 122,                  /* if_stmt  */
  YYSYMBOL_else_clause = 123,              /* else_clause  */
  YYSYMBOL_repeat_stmt = 124,              /* repeat_stmt  */
  YYSYMBOL_while_stmt = 125,               /* while_stmt  */
  YYSYMBOL_for_stmt = 126,                 /* for_stmt  */
  YYSYMBOL_case_stmt = 127,                /* case_stmt  */
  YYSYMBOL_case_expr_list = 128,           /* case_expr_list  */
  YYSYMBOL_case_expr = 129,                /* case_expr  */
  YYSYMBOL_goto_stmt = 130,                /* goto_stmt  */
  YYSYMBOL_expr_list = 131,                /* expr_list  */
  YYSYMBOL_args_list = 132,                /* args_list  */
  YYSYMBOL_expression = 133,               /* expression  */
  YYSYMBOL_expr = 134,                     /* expr  */
  YYSYMBOL_term = 135,                     /* term  */
  YYSYMBOL_factor = 136,                   /* factor  */
  YYSYMBOL_sys_proc = 137                  /* sys_proc  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYMAXUTOK   340


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   153,   155,   157,   159,   161,   163,   164,
     166,   167,   169,   171,   172,   173,   174,   175,   176,   178,
     179,   181,   182,   184,   186,   187,   188,   190,   191,   192,
     193,   195,   196,   197,   198,   199,   201,   202,   203,   204,
     205,   207,   209,   211,   212,   214,   215,   217,   219,   220,
     222,   223,   225,   226,   227,   229,   230,   232,   233,   235,
     236,   238,   240,   242,   244,   245,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   266,   267,   269,   270,   271,   272,
     273,   275,   277,   278,   280,   282,   284,   285,   287,   289,
     290,   292,   293,   295,   297,   298,   300,   301,   303,   304,
     305,   306,   307,   308,   309,   311,   312,   313,   314,   316,
     317,   318,   319,   320,   321,   322,   324,   325,   326,   327,
     328,   329,   330,   332,   333,   334
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "REV_AND", "REV_ARRAY",
  "REV_BEGIN", "REV_BREAK", "REV_CASE", "REV_CONST", "REV_CONTINUE",
  "REV_DEFAULT", "REV_DIV", "REV_DO", "REV_DOWNTO", "REV_ELSE", "REV_END",
  "REV_EXIT", "REV_FILE", "REV_FOR", "REV_FORWARD", "REV_FUNCTION",
  "REV_GOTO", "REV_IF", "REV_IN", "REV_LABEL", "REV_MOD", "REV_NIL",
  "REV_NOT", "REV_OF", "REV_OR", "REV_PACKED", "REV_PROCEDURE",
  "REV_PROGRAM", "REV_RECORD", "REV_REPEAT", "REV_SET", "REV_SIZEOF",
  "REV_THEN", "REV_TO", "REV_TYPE", "REV_UNTIL", "REV_VAR", "REV_WHILE",
  "REV_WITH", "REV_XOR", "REV_READ", "REV_WRITE", "REV_WRITELN", "OP_ADD",
  "OP_SUB", "OP_MOD", "OP_MUL", "OP_DIV", "OP_EQ", "OP_LT", "OP_GT",
  "OP_LBRAC", "OP_RBRAC", "OP_PERIOD", "OP_COMMA", "OP_COLON",
  "OP_SEMICOLON", "OP_AT", "OP_CARET", "OP_LPAREN", "OP_RPAREN", "OP_NE",
  "OP_LEQ", "OP_GEQ", "OP_ASSIGN", "OP_RANGE", "TYPE_INT", "TYPE_REAL",
  "TYPE_CHAR", "TYPE_BOOL", "TYPE_STRING", "BOOL_TRUE", "BOOL_FALSE",
  "IDT", "SIGN", "INT", "REAL", "CHAR", "ESC_CHAR", "STR", "COMMENT",
  "$accept", "root", "program", "program_heading", "routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_expr", "const_value", "type_part", "type_dec_list", "type_def",
  "type_dec", "simple_type", "sys_type", "range_type", "array_type",
  "record_type", "var_part", "var_dec_list", "var_dec", "id_list", "IDD",
  "routine_part", "sub_program", "parameters", "para_dec_list",
  "para_type_list", "routine_body", "compound_stmt", "statement_list",
  "statement", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expr_list", "args_list", "expression", "expr",
  "term", "factor", "sys_proc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
#endif

#define YYPACT_NINF (-215)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -43,    64,  -215,  -215,     7,  -215,    15,    83,   101,
    -215,  -215,  -215,  -215,  -215,    40,    82,    44,    58,    40,
    -215,    45,    88,   217,  -215,    53,    54,   217,  -215,   217,
    -215,  -215,  -215,    41,    77,   -39,  -215,    80,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,    79,   -55,  -215,    91,
      45,  -215,    69,     0,   217,   217,   217,  -215,  -215,    85,
    -215,  -215,  -215,  -215,  -215,    -4,   236,   -16,   117,  -215,
    -215,   -35,  -215,   286,   180,    72,   217,   233,   217,    86,
     217,  -215,   217,    89,    81,  -215,  -215,    69,  -215,   -12,
      92,    93,     0,  -215,  -215,  -215,   316,   217,   217,   333,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   227,   217,   227,    -9,
     340,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
     319,  -215,   340,    33,   340,    95,  -215,   110,    69,   -55,
      69,  -215,  -215,  -215,  -215,  -215,   102,   104,   116,  -215,
    -215,  -215,  -215,  -215,  -215,   103,    81,   115,   115,  -215,
    -215,    38,   335,   123,     3,    -1,  -215,   -16,   -16,   -16,
     -16,   -16,   -16,   117,   117,   117,  -215,  -215,  -215,  -215,
    -215,  -215,   283,   170,   340,  -215,   217,  -215,   119,   217,
    -215,  -215,   284,    -8,   122,    48,   108,   -40,  -215,  -215,
     132,    69,   136,   144,  -215,  -215,   227,   227,  -215,  -215,
     217,   217,   227,  -215,   340,   217,   340,   140,  -215,   131,
    -215,  -215,   -55,  -215,  -215,    73,   -37,  -215,   284,  -215,
     145,   148,   259,   264,  -215,   340,   182,   -55,  -215,  -215,
     284,    69,  -215,   155,   156,  -215,  -215,   227,   227,    81,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   157,  -215
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     7,     0,     1,     0,     0,     9,
       4,     3,    65,     5,    62,     0,    20,     0,     0,     8,
      11,     0,    44,     0,    63,     0,     0,     0,    65,     0,
     133,   134,   135,    51,     0,     0,    77,     0,    75,    76,
      78,    79,    80,    81,    82,    83,    88,     0,    10,     0,
      19,    22,     0,    54,     0,     0,     0,    17,    18,    51,
      13,    14,    15,    16,   127,   132,     0,   114,   118,   125,
      51,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,    64,     0,     0,     0,    21,    49,    43,    46,     0,
       0,     0,     6,    53,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,    68,    66,    67,    69,    70,    71,    72,    73,    74,
       0,    50,    84,     0,   105,   125,    12,     0,     0,     0,
       0,    33,    34,    32,    31,    35,    28,     0,     0,    24,
      27,    30,    25,    26,    45,     0,     0,    58,    58,    52,
     128,     0,     0,     0,     0,     0,   100,   112,   111,   109,
     113,   110,   108,   117,   115,   116,   124,   120,   123,   122,
     119,   121,     0,    93,    94,    95,     0,    87,     0,     0,
      89,    90,     0,     0,     0,     0,     0,     0,    23,    48,
       0,     0,     0,     0,   126,   131,     0,     0,    98,    99,
       0,     0,     0,    91,   106,     0,   104,     0,    42,     0,
      29,    40,     0,    36,    47,     0,     0,    60,     0,     7,
       0,     0,     0,     0,    92,    85,     0,     0,    37,    39,
       0,     0,    57,     0,     0,   101,   102,     0,     0,     0,
      38,    61,    59,     7,    56,    97,    96,    41,     0,    55
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,  -214,  -215,  -215,  -215,  -215,   200,
     -46,  -215,  -215,   171,  -153,  -182,  -215,  -215,  -215,  -215,
    -215,    97,   -85,  -129,   -17,  -215,   141,    65,  -215,    -5,
    -215,    -3,   196,  -112,   160,   162,   164,  -215,   165,   166,
     169,   173,  -215,    87,   176,  -215,   150,   -11,   242,     9,
     174,  -215
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     8,     9,    16,    19,    20,
      64,    22,    50,    51,   148,   149,   150,   151,   152,   153,
      53,    87,    88,    89,    65,    92,    93,   202,   226,   227,
      13,    36,    17,    37,    38,    39,    40,   213,    41,    42,
      43,    44,   165,   166,    45,   133,   119,   120,    67,    68,
      69,    46
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    83,   154,   200,   183,    14,   185,   218,    71,   222,
     217,   195,    66,   106,   208,   244,    73,    78,    75,    79,
      90,    57,    58,    79,   241,    60,    61,    62,   242,    63,
      80,    91,   107,   108,   115,     5,    57,    58,   147,   258,
      60,    61,    62,     1,    63,    96,   243,   155,   156,    12,
     186,    23,    98,   163,    79,   -86,   187,    35,   251,    24,
      35,    79,    25,   207,     6,    26,    27,   130,    10,   132,
      86,   134,   225,    11,   121,    57,    58,    70,    28,    60,
      61,    62,   164,    63,   118,   137,    29,   162,    12,    30,
      31,    32,   189,   194,   230,   231,   257,   186,   190,    35,
     234,    35,   -86,   204,   182,    76,   184,   155,   154,    15,
     147,    47,   225,   220,   138,   173,   174,   175,    18,   163,
     109,    21,    33,    49,    34,   100,   101,   102,   110,    52,
     139,    70,   155,   240,    72,   255,   256,    77,   103,   104,
     105,    81,   111,    82,    84,   140,   147,    86,   164,    97,
     136,   223,   141,   142,   143,   144,   145,    57,    58,   146,
     191,    60,    61,    62,   131,    63,   192,   112,   113,   114,
     157,   158,   196,   238,   197,   214,   239,   198,   216,   201,
     237,   199,   147,   206,   212,    12,   221,    23,   215,    35,
      35,   250,   219,   224,   147,    35,   228,   236,    25,   232,
     233,    26,    27,   147,   235,   229,   245,    57,    58,   246,
     249,    60,    61,    62,    28,    63,   253,   254,   259,    48,
     117,    85,    29,   203,    74,    30,    31,    32,    94,    95,
      35,    35,    12,   159,    23,   193,   252,   122,    12,   123,
      23,   124,   125,   126,    54,    25,   127,   161,    26,    27,
     128,    25,   209,   129,    26,    27,   135,     0,    33,     0,
      34,    28,     0,     0,    99,     0,    55,    28,     0,    29,
       0,   247,    30,    31,    32,    29,   248,     0,    30,    31,
      32,    56,     0,   176,   177,   178,   179,   180,   181,   100,
     101,   102,     0,    57,    58,    59,   210,    60,    61,    62,
       0,    63,   103,   104,   105,    33,     0,    34,     0,     0,
       0,    33,   100,   101,   102,     0,     0,   100,   101,   102,
       0,   211,     0,   116,     0,   103,   104,   105,     0,     0,
     103,   104,   105,   139,     0,     0,   100,   101,   102,   100,
     101,   102,   167,   168,   169,   170,   171,   172,   140,   103,
     104,   105,   103,   104,   105,   141,   142,   143,   144,   145,
      57,    58,   146,     0,    60,    61,    62,     0,    63,   100,
     101,   102,   100,   101,   102,     0,   188,     0,     0,     0,
       0,   160,   103,   104,   105,   103,   104,   105,   100,   101,
     102,     0,   205,   100,   101,   102,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,   103,   104,   105,    57,
      58,    70,     0,    60,    61,    62,     0,    63
};

static const yytype_int16 yycheck[] =
{
      17,    47,    87,   156,   116,     8,   118,    15,    25,    49,
     192,   140,    23,    29,    15,   229,    27,    56,    29,    58,
      20,    76,    77,    58,    61,    80,    81,    82,    65,    84,
      69,    31,    48,    49,    69,    78,    76,    77,    84,   253,
      80,    81,    82,    32,    84,    56,   228,    59,    60,     5,
      59,     7,    56,    99,    58,    14,    65,    74,   240,    15,
      77,    58,    18,    60,     0,    21,    22,    78,    61,    80,
      78,    82,   201,    58,    77,    76,    77,    78,    34,    80,
      81,    82,    99,    84,    12,     4,    42,    98,     5,    45,
      46,    47,    59,   139,   206,   207,   249,    59,    65,   116,
     212,   118,    61,    65,   115,    64,   117,    59,   193,     8,
     156,    53,   241,    65,    33,   106,   107,   108,    78,   165,
       3,    39,    78,    78,    80,    53,    54,    55,    11,    41,
      49,    78,    59,    60,    80,   247,   248,    60,    66,    67,
      68,    61,    25,    64,    53,    64,   192,    78,   165,    64,
      61,   197,    71,    72,    73,    74,    75,    76,    77,    78,
      65,    80,    81,    82,    78,    84,    56,    50,    51,    52,
      78,    78,    70,   219,    70,   186,   222,    61,   189,    64,
      49,    78,   228,    60,    14,     5,    78,     7,    69,   206,
     207,   237,    70,    61,   240,   212,    60,    57,    18,   210,
     211,    21,    22,   249,   215,    61,    61,    76,    77,    61,
      28,    80,    81,    82,    34,    84,    61,    61,    61,    19,
      40,    50,    42,   158,    28,    45,    46,    47,    54,    55,
     247,   248,     5,    92,     7,   138,   241,    77,     5,    77,
       7,    77,    77,    77,    27,    18,    77,    97,    21,    22,
      77,    18,   165,    77,    21,    22,    82,    -1,    78,    -1,
      80,    34,    -1,    -1,    28,    -1,    49,    34,    -1,    42,
      -1,    12,    45,    46,    47,    42,    12,    -1,    45,    46,
      47,    64,    -1,   109,   110,   111,   112,   113,   114,    53,
      54,    55,    -1,    76,    77,    78,    13,    80,    81,    82,
      -1,    84,    66,    67,    68,    78,    -1,    80,    -1,    -1,
      -1,    78,    53,    54,    55,    -1,    -1,    53,    54,    55,
      -1,    38,    -1,    37,    -1,    66,    67,    68,    -1,    -1,
      66,    67,    68,    49,    -1,    -1,    53,    54,    55,    53,
      54,    55,   100,   101,   102,   103,   104,   105,    64,    66,
      67,    68,    66,    67,    68,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    84,    53,
      54,    55,    53,    54,    55,    -1,    57,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    66,    67,    68,    53,    54,
      55,    -1,    57,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    66,    67,    68,    76,
      77,    78,    -1,    80,    81,    82,    -1,    84
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    87,    88,    89,    78,     0,    90,    91,    92,
      61,    58,     5,   116,   117,     8,    93,   118,    78,    94,
      95,    39,    97,     7,    15,    18,    21,    22,    34,    42,
      45,    46,    47,    78,    80,   110,   117,   119,   120,   121,
     122,   124,   125,   126,   127,   130,   137,    53,    95,    78,
      98,    99,    41,   106,    27,    49,    64,    76,    77,    78,
      80,    81,    82,    84,    96,   110,   133,   134,   135,   136,
      78,   110,    80,   133,   118,   133,    64,    60,    56,    58,
      69,    61,    64,    96,    53,    99,    78,   107,   108,   109,
      20,    31,   111,   112,   136,   136,   133,    64,    56,    28,
      53,    54,    55,    66,    67,    68,    29,    48,    49,     3,
      11,    25,    50,    51,    52,    69,    37,    40,    12,   132,
     133,   117,   120,   121,   122,   124,   125,   126,   127,   130,
     133,    78,   133,   131,   133,   136,    61,     4,    33,    49,
      64,    71,    72,    73,    74,    75,    78,    96,   100,   101,
     102,   103,   104,   105,   108,    59,    60,    78,    78,   112,
      65,   132,   133,    96,   110,   128,   129,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   133,   119,   133,   119,    59,    65,    57,    59,
      65,    65,    56,   107,    96,   109,    70,    70,    61,    78,
     100,    64,   113,   113,    65,    57,    60,    60,    15,   129,
      13,    38,    14,   123,   133,    69,   133,   101,    15,    70,
      65,    78,    49,    96,    61,   109,   114,   115,    60,    61,
     119,   119,   133,   133,   119,   133,    57,    49,    96,    96,
      60,    61,    65,   101,    90,    61,    61,    12,    12,    28,
      96,   101,   115,    61,    61,   119,   119,   100,    90,    61
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    89,    90,    91,    92,    93,    93,
      94,    94,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   104,   105,   106,   106,   107,   107,   108,   109,   109,
     110,   110,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   116,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   122,   123,   123,   124,   125,   126,   126,   127,   128,
     128,   129,   129,   130,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   137
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     5,     0,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     5,     4,
       3,     6,     3,     2,     0,     2,     1,     4,     3,     1,
       3,     1,     2,     1,     0,     8,     6,     3,     0,     3,
       1,     3,     1,     3,     3,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     1,     4,     1,     4,
       4,     5,     2,     0,     4,     4,     8,     8,     5,     2,
       1,     4,     4,     2,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     4,     1,     3,     2,
       2,     4,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 151 "pascal.y"
               {ast_root = (yyvsp[0].program); ast_root->prt(0);}
#line 1747 "pascal.cpp"
    break;

  case 3:
#line 153 "pascal.y"
                                             {(yyval.program)=new Program((yyvsp[-2].programh),(yyvsp[-1].rout));}
#line 1753 "pascal.cpp"
    break;

  case 4:
#line 155 "pascal.y"
                                               {(yyval.programh)=new ProgramHeading((yyvsp[-1].idt));}
#line 1759 "pascal.cpp"
    break;

  case 5:
#line 157 "pascal.y"
                                    {(yyval.rout)=new Routine((yyvsp[-1].routineh), (yyvsp[0].routineb));}
#line 1765 "pascal.cpp"
    break;

  case 6:
#line 159 "pascal.y"
                                                                     {(yyval.routineh)=new RoutineHead((yyvsp[-4].labelp),(yyvsp[-3].constp),(yyvsp[-2].typep),(yyvsp[-1].varp),(yyvsp[0].routinep));}
#line 1771 "pascal.cpp"
    break;

  case 7:
#line 161 "pascal.y"
             {(yyval.labelp)=new LabelPart();}
#line 1777 "pascal.cpp"
    break;

  case 8:
#line 163 "pascal.y"
                                       {(yyval.constp)=new ConstPart((yyvsp[0].constel));}
#line 1783 "pascal.cpp"
    break;

  case 9:
#line 164 "pascal.y"
                                       {(yyval.constp)=new ConstPart();}
#line 1789 "pascal.cpp"
    break;

  case 10:
#line 166 "pascal.y"
                                             {(yyval.constel)=(yyvsp[-1].constel); (yyval.constel)->add((yyvsp[0].conste));}
#line 1795 "pascal.cpp"
    break;

  case 11:
#line 167 "pascal.y"
                                             {(yyval.constel)=new ConstExprList(); (yyval.constel)->add((yyvsp[0].conste));}
#line 1801 "pascal.cpp"
    break;

  case 12:
#line 169 "pascal.y"
                                                {(yyval.conste)=new ConstExpr((yyvsp[-3].idt),(yyvsp[-1].constv));}
#line 1807 "pascal.cpp"
    break;

  case 13:
#line 171 "pascal.y"
                  {(yyval.constv)=new ConstValue((yyvsp[0].num));}
#line 1813 "pascal.cpp"
    break;

  case 14:
#line 172 "pascal.y"
                   {(yyval.constv)=new ConstValue((yyvsp[0].real));}
#line 1819 "pascal.cpp"
    break;

  case 15:
#line 173 "pascal.y"
                   {(yyval.constv)=new ConstValue((yyvsp[0].chr));}
#line 1825 "pascal.cpp"
    break;

  case 16:
#line 174 "pascal.y"
                  {std::string tmp = (yyvsp[0].str); (yyval.constv)=new ConstValue(tmp);}
#line 1831 "pascal.cpp"
    break;

  case 17:
#line 175 "pascal.y"
                        {(yyval.constv)=new ConstValue(ConstValue::TRUE);}
#line 1837 "pascal.cpp"
    break;

  case 18:
#line 176 "pascal.y"
                         {(yyval.constv)=new ConstValue(ConstValue::FALSE);}
#line 1843 "pascal.cpp"
    break;

  case 19:
#line 178 "pascal.y"
                                   {(yyval.typep)=new TypePart((yyvsp[0].tdl));}
#line 1849 "pascal.cpp"
    break;

  case 20:
#line 179 "pascal.y"
                                   {(yyval.typep)=new TypePart();}
#line 1855 "pascal.cpp"
    break;

  case 21:
#line 181 "pascal.y"
                                       {(yyval.tdl)=(yyvsp[-1].tdl); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1861 "pascal.cpp"
    break;

  case 22:
#line 182 "pascal.y"
                                       {(yyval.tdl)=new TypeDecList(); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1867 "pascal.cpp"
    break;

  case 23:
#line 184 "pascal.y"
                                           {(yyval.typedefi)=new TypeDef((yyvsp[-3].idt),(yyvsp[-1].typedec));}
#line 1873 "pascal.cpp"
    break;

  case 24:
#line 186 "pascal.y"
                       {(yyval.typedec)=new TypeDec((yyvsp[0].simplet));}
#line 1879 "pascal.cpp"
    break;

  case 25:
#line 187 "pascal.y"
                         {(yyval.typedec)=new TypeDec((yyvsp[0].arrayt));}
#line 1885 "pascal.cpp"
    break;

  case 26:
#line 188 "pascal.y"
                          {(yyval.typedec)=new TypeDec((yyvsp[0].recordt));}
#line 1891 "pascal.cpp"
    break;

  case 27:
#line 190 "pascal.y"
                       {(yyval.simplet)=new SimpleType((yyvsp[0].syst));}
#line 1897 "pascal.cpp"
    break;

  case 28:
#line 191 "pascal.y"
                  {(yyval.simplet)=new SimpleType((yyvsp[0].idt));}
#line 1903 "pascal.cpp"
    break;

  case 29:
#line 192 "pascal.y"
                                          {(yyval.simplet)=new SimpleType((yyvsp[-1].idl));}
#line 1909 "pascal.cpp"
    break;

  case 30:
#line 193 "pascal.y"
                         {(yyval.simplet)=new SimpleType((yyvsp[0].ranget));}
#line 1915 "pascal.cpp"
    break;

  case 31:
#line 195 "pascal.y"
                     {(yyval.syst)=new SysType(SysType::BOOLEAN);}
#line 1921 "pascal.cpp"
    break;

  case 32:
#line 196 "pascal.y"
                        {(yyval.syst)=new SysType(SysType::CHAR);}
#line 1927 "pascal.cpp"
    break;

  case 33:
#line 197 "pascal.y"
                       {(yyval.syst)=new SysType(SysType::INTEGER);}
#line 1933 "pascal.cpp"
    break;

  case 34:
#line 198 "pascal.y"
                        {(yyval.syst)=new SysType(SysType::REAL);}
#line 1939 "pascal.cpp"
    break;

  case 35:
#line 199 "pascal.y"
                          {(yyval.syst)=new SysType(SysType::STRING);}
#line 1945 "pascal.cpp"
    break;

  case 36:
#line 201 "pascal.y"
                                              {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv),false,false);}
#line 1951 "pascal.cpp"
    break;

  case 37:
#line 202 "pascal.y"
                                                      {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv), true,false);}
#line 1957 "pascal.cpp"
    break;

  case 38:
#line 203 "pascal.y"
                                                             {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), true,true);}
#line 1963 "pascal.cpp"
    break;

  case 39:
#line 204 "pascal.y"
                                                      {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), false,true);}
#line 1969 "pascal.cpp"
    break;

  case 40:
#line 205 "pascal.y"
                               {(yyval.ranget)=new RangeType((yyvsp[-2].idt), (yyvsp[0].idt));}
#line 1975 "pascal.cpp"
    break;

  case 41:
#line 207 "pascal.y"
                                                                     {(yyval.arrayt)=new ArrayType((yyvsp[-3].simplet),(yyvsp[0].typedec));}
#line 1981 "pascal.cpp"
    break;

  case 42:
#line 209 "pascal.y"
                                              {(yyval.recordt)=new RecordType((yyvsp[-1].vdl));}
#line 1987 "pascal.cpp"
    break;

  case 43:
#line 211 "pascal.y"
                                {(yyval.varp)=new VarPart((yyvsp[0].vdl));}
#line 1993 "pascal.cpp"
    break;

  case 44:
#line 212 "pascal.y"
                                {(yyval.varp)=new VarPart();}
#line 1999 "pascal.cpp"
    break;

  case 45:
#line 214 "pascal.y"
                                    {(yyval.vdl)=(yyvsp[-1].vdl); (yyval.vdl)->add((yyvsp[0].vard));}
#line 2005 "pascal.cpp"
    break;

  case 46:
#line 215 "pascal.y"
                      {(yyval.vdl)=new VarDecList(); (yyval.vdl)->add((yyvsp[0].vard));}
#line 2011 "pascal.cpp"
    break;

  case 47:
#line 217 "pascal.y"
                                                 {(yyval.vard)=new VarDec((yyvsp[-3].idl), (yyvsp[-1].typedec));}
#line 2017 "pascal.cpp"
    break;

  case 48:
#line 219 "pascal.y"
                               {(yyval.idl)=(yyvsp[-2].idl); (yyval.idl)->add((yyvsp[0].idt));}
#line 2023 "pascal.cpp"
    break;

  case 49:
#line 220 "pascal.y"
                  {(yyval.idl)=new IDList(); (yyval.idl)->add((yyvsp[0].idt));}
#line 2029 "pascal.cpp"
    break;

  case 50:
#line 222 "pascal.y"
                        {(yyval.idd)=(yyvsp[-2].idd); (yyval.idd)->add((yyvsp[0].idt));}
#line 2035 "pascal.cpp"
    break;

  case 51:
#line 223 "pascal.y"
                  {(yyval.idd)=new IDDotted(); (yyval.idd)->add((yyvsp[0].idt));}
#line 2041 "pascal.cpp"
    break;

  case 52:
#line 225 "pascal.y"
                                        {(yyval.routinep)=(yyvsp[-1].routinep); (yyval.routinep)->add((yyvsp[0].subp));}
#line 2047 "pascal.cpp"
    break;

  case 53:
#line 226 "pascal.y"
                                        {(yyval.routinep)=new RoutinePart(); (yyval.routinep)->add((yyvsp[0].subp));}
#line 2053 "pascal.cpp"
    break;

  case 54:
#line 227 "pascal.y"
                                        {(yyval.routinep)=new RoutinePart(); (yyval.routinep)->is_leaf = true;}
#line 2059 "pascal.cpp"
    break;

  case 55:
#line 229 "pascal.y"
                                                                                                 {(yyval.subp)=new SubProgram((yyvsp[-6].idt),(yyvsp[-5].param),(yyvsp[-3].simplet),(yyvsp[-1].rout));}
#line 2065 "pascal.cpp"
    break;

  case 56:
#line 230 "pascal.y"
                                                                             {(yyval.subp)=new SubProgram((yyvsp[-4].idt),(yyvsp[-3].param),(yyvsp[-1].rout));}
#line 2071 "pascal.cpp"
    break;

  case 57:
#line 232 "pascal.y"
                                                {(yyval.param)=new Parameters((yyvsp[-1].paradl));}
#line 2077 "pascal.cpp"
    break;

  case 58:
#line 233 "pascal.y"
                                                {(yyval.param)=new Parameters();}
#line 2083 "pascal.cpp"
    break;

  case 59:
#line 235 "pascal.y"
                                                          {(yyval.paradl)=(yyvsp[-2].paradl); (yyval.paradl)->add((yyvsp[0].paratl));}
#line 2089 "pascal.cpp"
    break;

  case 60:
#line 236 "pascal.y"
                                                          {(yyval.paradl)=new ParaDecList(); (yyval.paradl)->add((yyvsp[0].paratl));}
#line 2095 "pascal.cpp"
    break;

  case 61:
#line 238 "pascal.y"
                                              {(yyval.paratl)=new ParaTypeList((yyvsp[-2].idl),(yyvsp[0].simplet));}
#line 2101 "pascal.cpp"
    break;

  case 62:
#line 240 "pascal.y"
                             {(yyval.routineb)=new RoutineBody((yyvsp[0].compoundstmt));}
#line 2107 "pascal.cpp"
    break;

  case 63:
#line 242 "pascal.y"
                                                 {(yyval.compoundstmt)=new CompoundStmt((yyvsp[-1].stmtlst));}
#line 2113 "pascal.cpp"
    break;

  case 64:
#line 244 "pascal.y"
                                                        {(yyval.stmtlst)=(yyvsp[-2].stmtlst); (yyval.stmtlst)->add((yyvsp[-1].stmt));}
#line 2119 "pascal.cpp"
    break;

  case 65:
#line 245 "pascal.y"
                                                        {(yyval.stmtlst)=new StatementList();}
#line 2125 "pascal.cpp"
    break;

  case 66:
#line 247 "pascal.y"
                                       {(yyval.stmt)=new Statement((yyvsp[0].assignstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2131 "pascal.cpp"
    break;

  case 67:
#line 248 "pascal.y"
                                     {(yyval.stmt)=new Statement((yyvsp[0].procstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2137 "pascal.cpp"
    break;

  case 68:
#line 249 "pascal.y"
                                         {(yyval.stmt)=new Statement((yyvsp[0].compoundstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2143 "pascal.cpp"
    break;

  case 69:
#line 250 "pascal.y"
                                   {(yyval.stmt)=new Statement((yyvsp[0].ifstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2149 "pascal.cpp"
    break;

  case 70:
#line 251 "pascal.y"
                                       {(yyval.stmt)=new Statement((yyvsp[0].repeatstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2155 "pascal.cpp"
    break;

  case 71:
#line 252 "pascal.y"
                                      {(yyval.stmt)=new Statement((yyvsp[0].whilestmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2161 "pascal.cpp"
    break;

  case 72:
#line 253 "pascal.y"
                                    {(yyval.stmt)=new Statement((yyvsp[0].forstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2167 "pascal.cpp"
    break;

  case 73:
#line 254 "pascal.y"
                                     {(yyval.stmt)=new Statement((yyvsp[0].casestmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2173 "pascal.cpp"
    break;

  case 74:
#line 255 "pascal.y"
                                     {(yyval.stmt)=new Statement((yyvsp[0].gotostmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2179 "pascal.cpp"
    break;

  case 75:
#line 256 "pascal.y"
                          {(yyval.stmt)=new Statement((yyvsp[0].assignstmt));}
#line 2185 "pascal.cpp"
    break;

  case 76:
#line 257 "pascal.y"
                        {(yyval.stmt)=new Statement((yyvsp[0].procstmt));}
#line 2191 "pascal.cpp"
    break;

  case 77:
#line 258 "pascal.y"
                            {(yyval.stmt)=new Statement((yyvsp[0].compoundstmt));}
#line 2197 "pascal.cpp"
    break;

  case 78:
#line 259 "pascal.y"
                      {(yyval.stmt)=new Statement((yyvsp[0].ifstmt));}
#line 2203 "pascal.cpp"
    break;

  case 79:
#line 260 "pascal.y"
                          {(yyval.stmt)=new Statement((yyvsp[0].repeatstmt));}
#line 2209 "pascal.cpp"
    break;

  case 80:
#line 261 "pascal.y"
                         {(yyval.stmt)=new Statement((yyvsp[0].whilestmt));}
#line 2215 "pascal.cpp"
    break;

  case 81:
#line 262 "pascal.y"
                       {(yyval.stmt)=new Statement((yyvsp[0].forstmt));}
#line 2221 "pascal.cpp"
    break;

  case 82:
#line 263 "pascal.y"
                        {(yyval.stmt)=new Statement((yyvsp[0].casestmt));}
#line 2227 "pascal.cpp"
    break;

  case 83:
#line 264 "pascal.y"
                        {(yyval.stmt)=new Statement((yyvsp[0].gotostmt));}
#line 2233 "pascal.cpp"
    break;

  case 84:
#line 266 "pascal.y"
                                        {(yyval.assignstmt)=new AssignStmt((yyvsp[-2].idd), (yyvsp[0].texpression));}
#line 2239 "pascal.cpp"
    break;

  case 85:
#line 267 "pascal.y"
                                                                    {(yyval.assignstmt)=new AssignStmt((yyvsp[-5].idd),(yyvsp[-3].texpression),(yyvsp[0].texpression));}
#line 2245 "pascal.cpp"
    break;

  case 86:
#line 269 "pascal.y"
                  {(yyval.procstmt)=new ProcStmt((yyvsp[0].idt));}
#line 2251 "pascal.cpp"
    break;

  case 87:
#line 270 "pascal.y"
                                                {(yyval.procstmt)=new ProcStmt((yyvsp[-3].idt), (yyvsp[-1].argslist));}
#line 2257 "pascal.cpp"
    break;

  case 88:
#line 271 "pascal.y"
                       {(yyval.procstmt)=new ProcStmt((yyvsp[0].sysproc));}
#line 2263 "pascal.cpp"
    break;

  case 89:
#line 272 "pascal.y"
                                                     {(yyval.procstmt)=new ProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].exprlist));}
#line 2269 "pascal.cpp"
    break;

  case 90:
#line 273 "pascal.y"
                                                  {(yyval.procstmt)=new ProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].tfactor));}
#line 2275 "pascal.cpp"
    break;

  case 91:
#line 275 "pascal.y"
                                                               {(yyval.ifstmt)=new IfStmt((yyvsp[-3].texpression),(yyvsp[-1].stmt),(yyvsp[0].elseclause));}
#line 2281 "pascal.cpp"
    break;

  case 92:
#line 277 "pascal.y"
                                    {(yyval.elseclause)=new ElseClause((yyvsp[0].stmt));}
#line 2287 "pascal.cpp"
    break;

  case 93:
#line 278 "pascal.y"
                                    {(yyval.elseclause)=new ElseClause();}
#line 2293 "pascal.cpp"
    break;

  case 94:
#line 280 "pascal.y"
                                                             {(yyval.repeatstmt)=new RepeatStmt((yyvsp[-2].stmtlst),(yyvsp[0].texpression));}
#line 2299 "pascal.cpp"
    break;

  case 95:
#line 282 "pascal.y"
                                                    {(yyval.whilestmt)=new WhileStmt((yyvsp[-2].texpression),(yyvsp[0].stmt));}
#line 2305 "pascal.cpp"
    break;

  case 96:
#line 284 "pascal.y"
                                                                                  {(yyval.forstmt)=new ForStmt((yyvsp[-6].idd),(yyvsp[-4].texpression),(yyvsp[-2].texpression),(yyvsp[0].stmt),ForStmt::TO);}
#line 2311 "pascal.cpp"
    break;

  case 97:
#line 285 "pascal.y"
                                                                                      {(yyval.forstmt)=new ForStmt((yyvsp[-6].idd),(yyvsp[-4].texpression),(yyvsp[-2].texpression),(yyvsp[0].stmt),ForStmt::DOWNTO);}
#line 2317 "pascal.cpp"
    break;

  case 98:
#line 287 "pascal.y"
                                                                {(yyval.casestmt)=new CaseStmt((yyvsp[-3].texpression), (yyvsp[-1].caseexprlst));}
#line 2323 "pascal.cpp"
    break;

  case 99:
#line 289 "pascal.y"
                                          {(yyval.caseexprlst)=(yyvsp[-1].caseexprlst); (yyval.caseexprlst)->add((yyvsp[0].caseexpr));}
#line 2329 "pascal.cpp"
    break;

  case 100:
#line 290 "pascal.y"
                                          {(yyval.caseexprlst)=new CaseExprList(); (yyval.caseexprlst)->add((yyvsp[0].caseexpr));}
#line 2335 "pascal.cpp"
    break;

  case 101:
#line 292 "pascal.y"
                                                            {(yyval.caseexpr)=new CaseExpr((yyvsp[-3].constv), (yyvsp[-1].stmt));}
#line 2341 "pascal.cpp"
    break;

  case 102:
#line 293 "pascal.y"
                                                            {(yyval.caseexpr)=new CaseExpr((yyvsp[-3].idd), (yyvsp[-1].stmt));}
#line 2347 "pascal.cpp"
    break;

  case 103:
#line 295 "pascal.y"
                            {(yyval.gotostmt)=new GotoStmt((yyvsp[0].num));}
#line 2353 "pascal.cpp"
    break;

  case 104:
#line 297 "pascal.y"
                                            {(yyval.exprlist)=(yyvsp[-2].exprlist); (yyval.exprlist)->add((yyvsp[0].texpression));}
#line 2359 "pascal.cpp"
    break;

  case 105:
#line 298 "pascal.y"
                                            {(yyval.exprlist)=new ExprList(); (yyval.exprlist)->add((yyvsp[0].texpression));}
#line 2365 "pascal.cpp"
    break;

  case 106:
#line 300 "pascal.y"
                                            {(yyval.argslist)=(yyvsp[-2].argslist); (yyval.argslist)->add((yyvsp[0].texpression));}
#line 2371 "pascal.cpp"
    break;

  case 107:
#line 301 "pascal.y"
                                            {(yyval.argslist)=new ArgsList(); (yyval.argslist)->add((yyvsp[0].texpression));}
#line 2377 "pascal.cpp"
    break;

  case 108:
#line 303 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::GE, (yyvsp[0].texpr));}
#line 2383 "pascal.cpp"
    break;

  case 109:
#line 304 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::GT, (yyvsp[0].texpr));}
#line 2389 "pascal.cpp"
    break;

  case 110:
#line 305 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::LE, (yyvsp[0].texpr));}
#line 2395 "pascal.cpp"
    break;

  case 111:
#line 306 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::LT, (yyvsp[0].texpr));}
#line 2401 "pascal.cpp"
    break;

  case 112:
#line 307 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::EQ, (yyvsp[0].texpr));}
#line 2407 "pascal.cpp"
    break;

  case 113:
#line 308 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::NE, (yyvsp[0].texpr));}
#line 2413 "pascal.cpp"
    break;

  case 114:
#line 309 "pascal.y"
                                        {(yyval.texpression)=new Expression((yyvsp[0].texpr));}
#line 2419 "pascal.cpp"
    break;

  case 115:
#line 311 "pascal.y"
                                        {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::PULS, (yyvsp[0].tterm));}
#line 2425 "pascal.cpp"
    break;

  case 116:
#line 312 "pascal.y"
                                        {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::MINUS, (yyvsp[0].tterm));}
#line 2431 "pascal.cpp"
    break;

  case 117:
#line 313 "pascal.y"
                                        {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::OR, (yyvsp[0].tterm));}
#line 2437 "pascal.cpp"
    break;

  case 118:
#line 314 "pascal.y"
                                        {(yyval.texpr)=new Expr((yyvsp[0].tterm));}
#line 2443 "pascal.cpp"
    break;

  case 119:
#line 316 "pascal.y"
                                        {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MUL, (yyvsp[0].tfactor));}
#line 2449 "pascal.cpp"
    break;

  case 120:
#line 317 "pascal.y"
                                         {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::DIV, (yyvsp[0].tfactor));}
#line 2455 "pascal.cpp"
    break;

  case 121:
#line 318 "pascal.y"
                                        {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::DIV, (yyvsp[0].tfactor));}
#line 2461 "pascal.cpp"
    break;

  case 122:
#line 319 "pascal.y"
                                        {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MOD, (yyvsp[0].tfactor));}
#line 2467 "pascal.cpp"
    break;

  case 123:
#line 320 "pascal.y"
                                         {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MOD, (yyvsp[0].tfactor));}
#line 2473 "pascal.cpp"
    break;

  case 124:
#line 321 "pascal.y"
                                        {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::AND, (yyvsp[0].tfactor));}
#line 2479 "pascal.cpp"
    break;

  case 125:
#line 322 "pascal.y"
                                        {(yyval.tterm)=new Term((yyvsp[0].tfactor));}
#line 2485 "pascal.cpp"
    break;

  case 126:
#line 324 "pascal.y"
                                                 {(yyval.tfactor)=new Factor((yyvsp[-3].idt),(yyvsp[-1].argslist));}
#line 2491 "pascal.cpp"
    break;

  case 127:
#line 325 "pascal.y"
                                        {(yyval.tfactor)=new Factor((yyvsp[0].constv));}
#line 2497 "pascal.cpp"
    break;

  case 128:
#line 326 "pascal.y"
                                                {(yyval.tfactor)=new Factor((yyvsp[-1].texpression));}
#line 2503 "pascal.cpp"
    break;

  case 129:
#line 327 "pascal.y"
                                        {(yyval.tfactor)=new Factor((yyvsp[0].tfactor), Factor::NOT_FACTOR);}
#line 2509 "pascal.cpp"
    break;

  case 130:
#line 328 "pascal.y"
                                        {(yyval.tfactor)=new Factor((yyvsp[0].tfactor), Factor::MINUS_FACTOR);}
#line 2515 "pascal.cpp"
    break;

  case 131:
#line 329 "pascal.y"
                                                {(yyval.tfactor)=new Factor((yyvsp[-3].idd), (yyvsp[-1].texpression));}
#line 2521 "pascal.cpp"
    break;

  case 132:
#line 330 "pascal.y"
                                        {(yyval.tfactor)=new Factor((yyvsp[0].idd));}
#line 2527 "pascal.cpp"
    break;

  case 133:
#line 332 "pascal.y"
                                        {(yyval.sysproc)=new SysProc(SysProc::READ);}
#line 2533 "pascal.cpp"
    break;

  case 134:
#line 333 "pascal.y"
                                         {(yyval.sysproc)=new SysProc(SysProc::WRITE);}
#line 2539 "pascal.cpp"
    break;

  case 135:
#line 334 "pascal.y"
                                          {(yyval.sysproc)=new SysProc(SysProc::WRITELN);}
#line 2545 "pascal.cpp"
    break;


#line 2549 "pascal.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 335 "pascal.y"


int main() {
    yyparse();
    return 0; 
}

// int yyerror(char * s){ printf("%s\n",s); return 0; }
