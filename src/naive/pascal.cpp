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

#line 249 "pascal.cpp"

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
  YYSYMBOL_OP_ADD = 45,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 46,                    /* OP_SUB  */
  YYSYMBOL_OP_MUL = 47,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 48,                    /* OP_DIV  */
  YYSYMBOL_OP_EQ = 49,                     /* OP_EQ  */
  YYSYMBOL_OP_LT = 50,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 51,                     /* OP_GT  */
  YYSYMBOL_OP_LBRAC = 52,                  /* OP_LBRAC  */
  YYSYMBOL_OP_RBRAC = 53,                  /* OP_RBRAC  */
  YYSYMBOL_OP_PERIOD = 54,                 /* OP_PERIOD  */
  YYSYMBOL_OP_COMMA = 55,                  /* OP_COMMA  */
  YYSYMBOL_OP_COLON = 56,                  /* OP_COLON  */
  YYSYMBOL_OP_SEMICOLON = 57,              /* OP_SEMICOLON  */
  YYSYMBOL_OP_AT = 58,                     /* OP_AT  */
  YYSYMBOL_OP_CARET = 59,                  /* OP_CARET  */
  YYSYMBOL_OP_LPAREN = 60,                 /* OP_LPAREN  */
  YYSYMBOL_OP_RPAREN = 61,                 /* OP_RPAREN  */
  YYSYMBOL_OP_NE = 62,                     /* OP_NE  */
  YYSYMBOL_OP_LEQ = 63,                    /* OP_LEQ  */
  YYSYMBOL_OP_GEQ = 64,                    /* OP_GEQ  */
  YYSYMBOL_OP_ASSIGN = 65,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_RANGE = 66,                  /* OP_RANGE  */
  YYSYMBOL_TYPE_INT = 67,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_REAL = 68,                 /* TYPE_REAL  */
  YYSYMBOL_TYPE_CHAR = 69,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_BOOL = 70,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 71,               /* TYPE_STRING  */
  YYSYMBOL_BOOL_TRUE = 72,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 73,                /* BOOL_FALSE  */
  YYSYMBOL_IDT = 74,                       /* IDT  */
  YYSYMBOL_SIGN = 75,                      /* SIGN  */
  YYSYMBOL_INT = 76,                       /* INT  */
  YYSYMBOL_REAL = 77,                      /* REAL  */
  YYSYMBOL_CHAR = 78,                      /* CHAR  */
  YYSYMBOL_ESC_CHAR = 79,                  /* ESC_CHAR  */
  YYSYMBOL_STR = 80,                       /* STR  */
  YYSYMBOL_COMMENT = 81,                   /* COMMENT  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_root = 83,                      /* root  */
  YYSYMBOL_program = 84,                   /* program  */
  YYSYMBOL_program_heading = 85,           /* program_heading  */
  YYSYMBOL_routine = 86,                   /* routine  */
  YYSYMBOL_routine_head = 87,              /* routine_head  */
  YYSYMBOL_label_part = 88,                /* label_part  */
  YYSYMBOL_const_part = 89,                /* const_part  */
  YYSYMBOL_const_expr_list = 90,           /* const_expr_list  */
  YYSYMBOL_const_expr = 91,                /* const_expr  */
  YYSYMBOL_const_value = 92,               /* const_value  */
  YYSYMBOL_type_part = 93,                 /* type_part  */
  YYSYMBOL_type_dec_list = 94,             /* type_dec_list  */
  YYSYMBOL_type_def = 95,                  /* type_def  */
  YYSYMBOL_type_dec = 96,                  /* type_dec  */
  YYSYMBOL_simple_type = 97,               /* simple_type  */
  YYSYMBOL_sys_type = 98,                  /* sys_type  */
  YYSYMBOL_range_type = 99,                /* range_type  */
  YYSYMBOL_array_type = 100,               /* array_type  */
  YYSYMBOL_record_type = 101,              /* record_type  */
  YYSYMBOL_var_part = 102,                 /* var_part  */
  YYSYMBOL_var_dec_list = 103,             /* var_dec_list  */
  YYSYMBOL_var_dec = 104,                  /* var_dec  */
  YYSYMBOL_id_list = 105,                  /* id_list  */
  YYSYMBOL_routine_part = 106,             /* routine_part  */
  YYSYMBOL_routine_body = 107              /* routine_body  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  86

#define YYMAXUTOK   336


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
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    97,    97,    99,   101,   103,   105,   107,   109,   110,
     112,   113,   115,   117,   118,   119,   120,   121,   122,   124,
     125,   127,   128,   130,   132,   133,   134,   136,   137,   138,
     139,   141,   142,   143,   144,   145,   147,   148,   149,   150,
     151,   153,   155,   157,   158,   160,   161,   163,   165,   166,
     168,   170
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
  "REV_WITH", "REV_XOR", "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_EQ",
  "OP_LT", "OP_GT", "OP_LBRAC", "OP_RBRAC", "OP_PERIOD", "OP_COMMA",
  "OP_COLON", "OP_SEMICOLON", "OP_AT", "OP_CARET", "OP_LPAREN",
  "OP_RPAREN", "OP_NE", "OP_LEQ", "OP_GEQ", "OP_ASSIGN", "OP_RANGE",
  "TYPE_INT", "TYPE_REAL", "TYPE_CHAR", "TYPE_BOOL", "TYPE_STRING",
  "BOOL_TRUE", "BOOL_FALSE", "IDT", "SIGN", "INT", "REAL", "CHAR",
  "ESC_CHAR", "STR", "COMMENT", "$accept", "root", "program",
  "program_heading", "routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_expr", "const_value", "type_part",
  "type_dec_list", "type_def", "type_dec", "simple_type", "sys_type",
  "range_type", "array_type", "record_type", "var_part", "var_dec_list",
  "var_dec", "id_list", "routine_part", "routine_body", YY_NULLPTR
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
     335,   336
};
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -24,   -69,    13,   -70,   -70,   -33,   -70,   -36,   -70,    12,
     -70,   -70,   -70,   -52,    -1,   -22,   -52,   -70,   -30,    14,
     -66,   -70,    -2,   -30,   -70,   -16,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     2,    -4,   -70,   -70,   -16,   -70,   -39,
     -70,   -70,     8,   -16,   -66,   -16,   -70,   -70,   -70,   -70,
     -70,     5,     9,    20,   -70,   -70,   -70,   -70,   -70,   -70,
       7,    -4,   -37,   -12,    19,   -40,    15,   -27,   -70,   -70,
      23,    34,   -70,     6,   -70,   -70,   -66,   -70,   -70,    60,
     -66,   -70,   -70,    -4,   -70,   -70
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     7,     0,     1,     0,    51,     9,
       4,     3,     5,     0,    20,     0,     8,    11,     0,    44,
       0,    10,     0,    19,    22,     0,    50,    17,    18,    13,
      14,    15,    16,     0,     0,    21,    49,    43,    46,     0,
       6,    12,     0,     0,     0,     0,    33,    34,    32,    31,
      35,    28,     0,     0,    24,    27,    30,    25,    26,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    48,
       0,     0,    42,     0,    29,    40,     0,    36,    47,     0,
       0,    37,    39,     0,    38,    41
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    74,
     -19,   -70,   -70,    68,   -57,    30,   -70,   -70,   -70,   -70,
     -70,    50,   -35,    49,   -70,   -70
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     8,     9,    14,    16,    17,
      52,    19,    23,    24,    53,    54,    55,    56,    57,    58,
      26,    37,    38,    39,    40,    12
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    33,    59,    72,    70,     5,    27,    28,     1,    44,
      29,    30,    31,     6,    32,    60,    60,    61,    11,    76,
      13,    74,    15,    45,    10,    64,    85,    20,    59,    43,
      46,    47,    48,    49,    50,    27,    28,    51,    18,    29,
      30,    31,    44,    32,    22,    27,    28,    34,    77,    29,
      30,    31,    80,    32,    81,    25,    45,    82,    36,    41,
      62,    84,    36,    46,    47,    48,    49,    50,    27,    28,
      51,    66,    29,    30,    31,    67,    32,    68,    27,    28,
      78,    69,    29,    30,    31,    73,    32,    79,    83,    75,
      21,    35,    71,    63,    65
};

static const yytype_int8 yycheck[] =
{
       4,    20,    37,    15,    61,    74,    72,    73,    32,    46,
      76,    77,    78,     0,    80,    55,    55,    56,    54,    46,
       8,    61,    74,    60,    57,    44,    83,    49,    63,    33,
      67,    68,    69,    70,    71,    72,    73,    74,    39,    76,
      77,    78,    46,    80,    74,    72,    73,    49,    67,    76,
      77,    78,    46,    80,    73,    41,    60,    76,    74,    57,
      52,    80,    74,    67,    68,    69,    70,    71,    72,    73,
      74,    66,    76,    77,    78,    66,    80,    57,    72,    73,
      57,    74,    76,    77,    78,    66,    80,    53,    28,    74,
      16,    23,    62,    43,    45
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    83,    84,    85,    74,     0,    86,    87,    88,
      57,    54,   107,     8,    89,    74,    90,    91,    39,    93,
      49,    91,    74,    94,    95,    41,   102,    72,    73,    76,
      77,    78,    80,    92,    49,    95,    74,   103,   104,   105,
     106,    57,     4,    33,    46,    60,    67,    68,    69,    70,
      71,    74,    92,    96,    97,    98,    99,   100,   101,   104,
      55,    56,    52,   103,    92,   105,    66,    66,    57,    74,
      96,    97,    15,    66,    61,    74,    46,    92,    57,    53,
      46,    92,    92,    28,    92,    96
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    84,    85,    86,    87,    88,    89,    89,
      90,    90,    91,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    96,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,   100,   101,   102,   102,   103,   103,   104,   105,   105,
     106,   107
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     5,     0,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     5,     4,
       3,     6,     3,     2,     0,     2,     1,     4,     3,     1,
       0,     0
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
#line 97 "pascal.y"
               {ast_root = (yyvsp[0].program); ast_root->prt(0);}
#line 1535 "pascal.cpp"
    break;

  case 3:
#line 99 "pascal.y"
                                             {(yyval.program)=new Program((yyvsp[-2].programh),(yyvsp[-1].rout));}
#line 1541 "pascal.cpp"
    break;

  case 4:
#line 101 "pascal.y"
                                               {(yyval.programh)=new ProgramHeading((yyvsp[-1].idt));}
#line 1547 "pascal.cpp"
    break;

  case 5:
#line 103 "pascal.y"
                                    {(yyval.rout)=new Routine((yyvsp[-1].routineh), (yyvsp[0].routineb));}
#line 1553 "pascal.cpp"
    break;

  case 6:
#line 105 "pascal.y"
                                                                     {(yyval.routineh)=new RoutineHead((yyvsp[-4].labelp),(yyvsp[-3].constp),(yyvsp[-2].typep),(yyvsp[-1].varp),(yyvsp[0].routinep));}
#line 1559 "pascal.cpp"
    break;

  case 7:
#line 107 "pascal.y"
             {(yyval.labelp)=new LabelPart();}
#line 1565 "pascal.cpp"
    break;

  case 8:
#line 109 "pascal.y"
                                       {(yyval.constp)=new ConstPart((yyvsp[0].constel));}
#line 1571 "pascal.cpp"
    break;

  case 9:
#line 110 "pascal.y"
                                       {(yyval.constp)=new ConstPart();}
#line 1577 "pascal.cpp"
    break;

  case 10:
#line 112 "pascal.y"
                                             {(yyval.constel)=(yyvsp[-1].constel); (yyval.constel)->add((yyvsp[0].conste));}
#line 1583 "pascal.cpp"
    break;

  case 11:
#line 113 "pascal.y"
                                             {(yyval.constel)=new ConstExprList(); (yyval.constel)->add((yyvsp[0].conste));}
#line 1589 "pascal.cpp"
    break;

  case 12:
#line 115 "pascal.y"
                                                {(yyval.conste)=new ConstExpr((yyvsp[-3].idt),(yyvsp[-1].constv));}
#line 1595 "pascal.cpp"
    break;

  case 13:
#line 117 "pascal.y"
                  {(yyval.constv)=new ConstValue((yyvsp[0].num));}
#line 1601 "pascal.cpp"
    break;

  case 14:
#line 118 "pascal.y"
                   {(yyval.constv)=new ConstValue((yyvsp[0].real));}
#line 1607 "pascal.cpp"
    break;

  case 15:
#line 119 "pascal.y"
                   {(yyval.constv)=new ConstValue((yyvsp[0].chr));}
#line 1613 "pascal.cpp"
    break;

  case 16:
#line 120 "pascal.y"
                  {std::string tmp = (yyvsp[0].str); (yyval.constv)=new ConstValue(tmp);}
#line 1619 "pascal.cpp"
    break;

  case 17:
#line 121 "pascal.y"
                        {(yyval.constv)=new ConstValue(ConstValue::TRUE);}
#line 1625 "pascal.cpp"
    break;

  case 18:
#line 122 "pascal.y"
                         {(yyval.constv)=new ConstValue(ConstValue::FALSE);}
#line 1631 "pascal.cpp"
    break;

  case 19:
#line 124 "pascal.y"
                                   {(yyval.typep)=new TypePart((yyvsp[0].tdl));}
#line 1637 "pascal.cpp"
    break;

  case 20:
#line 125 "pascal.y"
                                   {(yyval.typep)=new TypePart();}
#line 1643 "pascal.cpp"
    break;

  case 21:
#line 127 "pascal.y"
                                       {(yyval.tdl)=(yyvsp[-1].tdl); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1649 "pascal.cpp"
    break;

  case 22:
#line 128 "pascal.y"
                                       {(yyval.tdl)=new TypeDecList(); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1655 "pascal.cpp"
    break;

  case 23:
#line 130 "pascal.y"
                                           {(yyval.typedefi)=new TypeDef((yyvsp[-3].idt),(yyvsp[-1].typedec));}
#line 1661 "pascal.cpp"
    break;

  case 24:
#line 132 "pascal.y"
                       {(yyval.typedec)=new TypeDec((yyvsp[0].simplet));}
#line 1667 "pascal.cpp"
    break;

  case 25:
#line 133 "pascal.y"
                         {(yyval.typedec)=new TypeDec((yyvsp[0].arrayt));}
#line 1673 "pascal.cpp"
    break;

  case 26:
#line 134 "pascal.y"
                          {(yyval.typedec)=new TypeDec((yyvsp[0].recordt));}
#line 1679 "pascal.cpp"
    break;

  case 27:
#line 136 "pascal.y"
                       {(yyval.simplet)=new SimpleType((yyvsp[0].syst));}
#line 1685 "pascal.cpp"
    break;

  case 28:
#line 137 "pascal.y"
                  {(yyval.simplet)=new SimpleType((yyvsp[0].idt));}
#line 1691 "pascal.cpp"
    break;

  case 29:
#line 138 "pascal.y"
                                          {(yyval.simplet)=new SimpleType((yyvsp[-1].idl));}
#line 1697 "pascal.cpp"
    break;

  case 30:
#line 139 "pascal.y"
                         {(yyval.simplet)=new SimpleType((yyvsp[0].ranget));}
#line 1703 "pascal.cpp"
    break;

  case 31:
#line 141 "pascal.y"
                     {(yyval.syst)=new SysType(SysType::BOOLEAN);}
#line 1709 "pascal.cpp"
    break;

  case 32:
#line 142 "pascal.y"
                        {(yyval.syst)=new SysType(SysType::CHAR);}
#line 1715 "pascal.cpp"
    break;

  case 33:
#line 143 "pascal.y"
                       {(yyval.syst)=new SysType(SysType::INTEGER);}
#line 1721 "pascal.cpp"
    break;

  case 34:
#line 144 "pascal.y"
                        {(yyval.syst)=new SysType(SysType::REAL);}
#line 1727 "pascal.cpp"
    break;

  case 35:
#line 145 "pascal.y"
                          {(yyval.syst)=new SysType(SysType::STRING);}
#line 1733 "pascal.cpp"
    break;

  case 36:
#line 147 "pascal.y"
                                              {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv),false,false);}
#line 1739 "pascal.cpp"
    break;

  case 37:
#line 148 "pascal.y"
                                                      {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv), true,false);}
#line 1745 "pascal.cpp"
    break;

  case 38:
#line 149 "pascal.y"
                                                             {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), true,true);}
#line 1751 "pascal.cpp"
    break;

  case 39:
#line 150 "pascal.y"
                                                      {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), false,true);}
#line 1757 "pascal.cpp"
    break;

  case 40:
#line 151 "pascal.y"
                               {(yyval.ranget)=new RangeType((yyvsp[-2].idt), (yyvsp[0].idt));}
#line 1763 "pascal.cpp"
    break;

  case 41:
#line 153 "pascal.y"
                                                                     {(yyval.arrayt)=new ArrayType((yyvsp[-3].simplet),(yyvsp[0].typedec));}
#line 1769 "pascal.cpp"
    break;

  case 42:
#line 155 "pascal.y"
                                              {(yyval.recordt)=new RecordType((yyvsp[-1].vdl));}
#line 1775 "pascal.cpp"
    break;

  case 43:
#line 157 "pascal.y"
                                {(yyval.varp)=new VarPart((yyvsp[0].vdl));}
#line 1781 "pascal.cpp"
    break;

  case 44:
#line 158 "pascal.y"
                                {(yyval.varp)=new VarPart();}
#line 1787 "pascal.cpp"
    break;

  case 45:
#line 160 "pascal.y"
                                    {(yyval.vdl)=(yyvsp[-1].vdl); (yyval.vdl)->add((yyvsp[0].vard));}
#line 1793 "pascal.cpp"
    break;

  case 46:
#line 161 "pascal.y"
                      {(yyval.vdl)=new VarDecList(); (yyval.vdl)->add((yyvsp[0].vard));}
#line 1799 "pascal.cpp"
    break;

  case 47:
#line 163 "pascal.y"
                                                 {(yyval.vard)=new VarDec((yyvsp[-3].idl), (yyvsp[-1].typedec));}
#line 1805 "pascal.cpp"
    break;

  case 48:
#line 165 "pascal.y"
                               {(yyval.idl)=(yyvsp[-2].idl); (yyval.idl)->add((yyvsp[0].idt));}
#line 1811 "pascal.cpp"
    break;

  case 49:
#line 166 "pascal.y"
                  {(yyval.idl)=new IDList(); (yyval.idl)->add((yyvsp[0].idt));}
#line 1817 "pascal.cpp"
    break;

  case 50:
#line 168 "pascal.y"
               {(yyval.routinep)=new RoutinePart();}
#line 1823 "pascal.cpp"
    break;

  case 51:
#line 170 "pascal.y"
               {(yyval.routineb)=new RoutineBody();}
#line 1829 "pascal.cpp"
    break;


#line 1833 "pascal.cpp"

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

#line 171 "pascal.y"


int main() {
    yyparse();
    return 0; 
}

// int yyerror(char * s){ printf("%s\n",s); return 0; }
