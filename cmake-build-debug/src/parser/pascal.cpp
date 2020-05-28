/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"

#include "ast/ast.h"

Program* ast_root;

extern int yylex();
extern void yyerror(const char * s);

#line 79 "pascal.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
#line 3 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"

#define MAX_STR_LEN 1024

#line 117 "pascal.cpp"

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

#line 272 "pascal.cpp"

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



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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

#define YYUNDEFTOK  2
#define YYMAXUTOK   340

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REV_AND", "REV_ARRAY", "REV_BEGIN",
  "REV_BREAK", "REV_CASE", "REV_CONST", "REV_CONTINUE", "REV_DEFAULT",
  "REV_DIV", "REV_DO", "REV_DOWNTO", "REV_ELSE", "REV_END", "REV_EXIT",
  "REV_FILE", "REV_FOR", "REV_FORWARD", "REV_FUNCTION", "REV_GOTO",
  "REV_IF", "REV_IN", "REV_LABEL", "REV_MOD", "REV_NIL", "REV_NOT",
  "REV_OF", "REV_OR", "REV_PACKED", "REV_PROCEDURE", "REV_PROGRAM",
  "REV_RECORD", "REV_REPEAT", "REV_SET", "REV_SIZEOF", "REV_THEN",
  "REV_TO", "REV_TYPE", "REV_UNTIL", "REV_VAR", "REV_WHILE", "REV_WITH",
  "REV_XOR", "REV_READ", "REV_WRITE", "REV_WRITELN", "OP_ADD", "OP_SUB",
  "OP_MOD", "OP_MUL", "OP_DIV", "OP_EQ", "OP_LT", "OP_GT", "OP_LBRAC",
  "OP_RBRAC", "OP_PERIOD", "OP_COMMA", "OP_COLON", "OP_SEMICOLON", "OP_AT",
  "OP_CARET", "OP_LPAREN", "OP_RPAREN", "OP_NE", "OP_LEQ", "OP_GEQ",
  "OP_ASSIGN", "OP_RANGE", "TYPE_INT", "TYPE_REAL", "TYPE_CHAR",
  "TYPE_BOOL", "TYPE_STRING", "BOOL_TRUE", "BOOL_FALSE", "IDT", "SIGN",
  "INT", "REAL", "CHAR", "ESC_CHAR", "STR", "COMMENT", "$accept", "root",
  "program", "program_heading", "routine", "routine_head", "label_part",
  "const_part", "const_expr_list", "const_expr", "const_value",
  "type_part", "type_dec_list", "type_def", "type_dec", "simple_type",
  "sys_type", "range_type", "array_type", "record_type", "var_part",
  "var_dec_list", "var_dec", "id_list", "IDD", "routine_part",
  "sub_program", "parameters", "para_dec_list", "para_type_list",
  "routine_body", "compound_stmt", "statement_list", "statement",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "case_stmt", "case_expr_list", "case_expr",
  "goto_stmt", "expr_list", "args_list", "expression", "expr", "term",
  "factor", "sys_proc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
# endif

#define YYPACT_NINF -215

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-215)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,  -214,  -215,  -215,  -215,  -215,   200,
     -46,  -215,  -215,   171,  -153,  -182,  -215,  -215,  -215,  -215,
    -215,    97,   -85,  -129,   -17,  -215,   141,    65,  -215,    -5,
    -215,    -3,   196,  -112,   160,   162,   164,  -215,   165,   166,
     169,   173,  -215,    87,   176,  -215,   150,   -11,   242,     9,
     174,  -215
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     8,     9,    16,    19,    20,
      64,    22,    50,    51,   148,   149,   150,   151,   152,   153,
      53,    87,    88,    89,    65,    92,    93,   202,   226,   227,
      13,    36,    17,    37,    38,    39,    40,   213,    41,    42,
      43,    44,   165,   166,    45,   133,   119,   120,    67,    68,
      69,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
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

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
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
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
#line 151 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {ast_root = (yyvsp[0].program); ast_root->prt(0);}
#line 1711 "pascal.cpp"
    break;

  case 3:
#line 153 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.program)=new Program((yyvsp[-2].programh),(yyvsp[-1].rout));}
#line 1717 "pascal.cpp"
    break;

  case 4:
#line 155 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.programh)=new ProgramHeading((yyvsp[-1].idt));}
#line 1723 "pascal.cpp"
    break;

  case 5:
#line 157 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.rout)=new Routine((yyvsp[-1].routineh), (yyvsp[0].routineb));}
#line 1729 "pascal.cpp"
    break;

  case 6:
#line 159 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.routineh)=new RoutineHead((yyvsp[-4].labelp),(yyvsp[-3].constp),(yyvsp[-2].typep),(yyvsp[-1].varp),(yyvsp[0].routinep));}
#line 1735 "pascal.cpp"
    break;

  case 7:
#line 161 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.labelp)=new LabelPart();}
#line 1741 "pascal.cpp"
    break;

  case 8:
#line 163 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constp)=new ConstPart((yyvsp[0].constel));}
#line 1747 "pascal.cpp"
    break;

  case 9:
#line 164 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constp)=new ConstPart();}
#line 1753 "pascal.cpp"
    break;

  case 10:
#line 166 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constel)=(yyvsp[-1].constel); (yyval.constel)->add((yyvsp[0].conste));}
#line 1759 "pascal.cpp"
    break;

  case 11:
#line 167 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constel)=new ConstExprList(); (yyval.constel)->add((yyvsp[0].conste));}
#line 1765 "pascal.cpp"
    break;

  case 12:
#line 169 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.conste)=new ConstExpr((yyvsp[-3].idt),(yyvsp[-1].constv));}
#line 1771 "pascal.cpp"
    break;

  case 13:
#line 171 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constv)=new ConstValue((yyvsp[0].num));}
#line 1777 "pascal.cpp"
    break;

  case 14:
#line 172 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constv)=new ConstValue((yyvsp[0].real));}
#line 1783 "pascal.cpp"
    break;

  case 15:
#line 173 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constv)=new ConstValue((yyvsp[0].chr));}
#line 1789 "pascal.cpp"
    break;

  case 16:
#line 174 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {std::string tmp = (yyvsp[0].str); (yyval.constv)=new ConstValue(tmp);}
#line 1795 "pascal.cpp"
    break;

  case 17:
#line 175 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constv)=new ConstValue(ConstValue::TRUE);}
#line 1801 "pascal.cpp"
    break;

  case 18:
#line 176 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.constv)=new ConstValue(ConstValue::FALSE);}
#line 1807 "pascal.cpp"
    break;

  case 19:
#line 178 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typep)=new TypePart((yyvsp[0].tdl));}
#line 1813 "pascal.cpp"
    break;

  case 20:
#line 179 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typep)=new TypePart();}
#line 1819 "pascal.cpp"
    break;

  case 21:
#line 181 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tdl)=(yyvsp[-1].tdl); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1825 "pascal.cpp"
    break;

  case 22:
#line 182 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tdl)=new TypeDecList(); (yyval.tdl)->add((yyvsp[0].typedefi));}
#line 1831 "pascal.cpp"
    break;

  case 23:
#line 184 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typedefi)=new TypeDef((yyvsp[-3].idt),(yyvsp[-1].typedec));}
#line 1837 "pascal.cpp"
    break;

  case 24:
#line 186 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typedec)=new TypeDec((yyvsp[0].simplet));}
#line 1843 "pascal.cpp"
    break;

  case 25:
#line 187 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typedec)=new TypeDec((yyvsp[0].arrayt));}
#line 1849 "pascal.cpp"
    break;

  case 26:
#line 188 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.typedec)=new TypeDec((yyvsp[0].recordt));}
#line 1855 "pascal.cpp"
    break;

  case 27:
#line 190 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.simplet)=new SimpleType((yyvsp[0].syst));}
#line 1861 "pascal.cpp"
    break;

  case 28:
#line 191 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.simplet)=new SimpleType((yyvsp[0].idt));}
#line 1867 "pascal.cpp"
    break;

  case 29:
#line 192 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.simplet)=new SimpleType((yyvsp[-1].idl));}
#line 1873 "pascal.cpp"
    break;

  case 30:
#line 193 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.simplet)=new SimpleType((yyvsp[0].ranget));}
#line 1879 "pascal.cpp"
    break;

  case 31:
#line 195 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.syst)=new SysType(SysType::BOOLEAN);}
#line 1885 "pascal.cpp"
    break;

  case 32:
#line 196 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.syst)=new SysType(SysType::CHAR);}
#line 1891 "pascal.cpp"
    break;

  case 33:
#line 197 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.syst)=new SysType(SysType::INTEGER);}
#line 1897 "pascal.cpp"
    break;

  case 34:
#line 198 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.syst)=new SysType(SysType::REAL);}
#line 1903 "pascal.cpp"
    break;

  case 35:
#line 199 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.syst)=new SysType(SysType::STRING);}
#line 1909 "pascal.cpp"
    break;

  case 36:
#line 201 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv),false,false);}
#line 1915 "pascal.cpp"
    break;

  case 37:
#line 202 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ranget)=new RangeType((yyvsp[-2].constv),(yyvsp[0].constv), true,false);}
#line 1921 "pascal.cpp"
    break;

  case 38:
#line 203 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), true,true);}
#line 1927 "pascal.cpp"
    break;

  case 39:
#line 204 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ranget)=new RangeType((yyvsp[-3].constv),(yyvsp[0].constv), false,true);}
#line 1933 "pascal.cpp"
    break;

  case 40:
#line 205 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ranget)=new RangeType((yyvsp[-2].idt), (yyvsp[0].idt));}
#line 1939 "pascal.cpp"
    break;

  case 41:
#line 207 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.arrayt)=new ArrayType((yyvsp[-3].simplet),(yyvsp[0].typedec));}
#line 1945 "pascal.cpp"
    break;

  case 42:
#line 209 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.recordt)=new RecordType((yyvsp[-1].vdl));}
#line 1951 "pascal.cpp"
    break;

  case 43:
#line 211 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.varp)=new VarPart((yyvsp[0].vdl));}
#line 1957 "pascal.cpp"
    break;

  case 44:
#line 212 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.varp)=new VarPart();}
#line 1963 "pascal.cpp"
    break;

  case 45:
#line 214 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.vdl)=(yyvsp[-1].vdl); (yyval.vdl)->add((yyvsp[0].vard));}
#line 1969 "pascal.cpp"
    break;

  case 46:
#line 215 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.vdl)=new VarDecList(); (yyval.vdl)->add((yyvsp[0].vard));}
#line 1975 "pascal.cpp"
    break;

  case 47:
#line 217 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.vard)=new VarDec((yyvsp[-3].idl), (yyvsp[-1].typedec));}
#line 1981 "pascal.cpp"
    break;

  case 48:
#line 219 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.idl)=(yyvsp[-2].idl); (yyval.idl)->add((yyvsp[0].idt));}
#line 1987 "pascal.cpp"
    break;

  case 49:
#line 220 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.idl)=new IDList(); (yyval.idl)->add((yyvsp[0].idt));}
#line 1993 "pascal.cpp"
    break;

  case 50:
#line 222 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.idd)=(yyvsp[-2].idd); (yyval.idd)->add((yyvsp[0].idt));}
#line 1999 "pascal.cpp"
    break;

  case 51:
#line 223 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.idd)=new IDDotted(); (yyval.idd)->add((yyvsp[0].idt));}
#line 2005 "pascal.cpp"
    break;

  case 52:
#line 225 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.routinep)=(yyvsp[-1].routinep); (yyval.routinep)->add((yyvsp[0].subp));}
#line 2011 "pascal.cpp"
    break;

  case 53:
#line 226 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.routinep)=new RoutinePart(); (yyval.routinep)->add((yyvsp[0].subp));}
#line 2017 "pascal.cpp"
    break;

  case 54:
#line 227 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.routinep)=new RoutinePart(); (yyval.routinep)->is_leaf = true;}
#line 2023 "pascal.cpp"
    break;

  case 55:
#line 229 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.subp)=new SubProgram((yyvsp[-6].idt),(yyvsp[-5].param),(yyvsp[-3].simplet),(yyvsp[-1].rout));}
#line 2029 "pascal.cpp"
    break;

  case 56:
#line 230 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.subp)=new SubProgram((yyvsp[-4].idt),(yyvsp[-3].param),(yyvsp[-1].rout));}
#line 2035 "pascal.cpp"
    break;

  case 57:
#line 232 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.param)=new Parameters((yyvsp[-1].paradl));}
#line 2041 "pascal.cpp"
    break;

  case 58:
#line 233 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.param)=new Parameters();}
#line 2047 "pascal.cpp"
    break;

  case 59:
#line 235 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.paradl)=(yyvsp[-2].paradl); (yyval.paradl)->add((yyvsp[0].paratl));}
#line 2053 "pascal.cpp"
    break;

  case 60:
#line 236 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.paradl)=new ParaDecList(); (yyval.paradl)->add((yyvsp[0].paratl));}
#line 2059 "pascal.cpp"
    break;

  case 61:
#line 238 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.paratl)=new ParaTypeList((yyvsp[-2].idl),(yyvsp[0].simplet));}
#line 2065 "pascal.cpp"
    break;

  case 62:
#line 240 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.routineb)=new RoutineBody((yyvsp[0].compoundstmt));}
#line 2071 "pascal.cpp"
    break;

  case 63:
#line 242 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.compoundstmt)=new CompoundStmt((yyvsp[-1].stmtlst));}
#line 2077 "pascal.cpp"
    break;

  case 64:
#line 244 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmtlst)=(yyvsp[-2].stmtlst); (yyval.stmtlst)->add((yyvsp[-1].stmt));}
#line 2083 "pascal.cpp"
    break;

  case 65:
#line 245 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmtlst)=new StatementList();}
#line 2089 "pascal.cpp"
    break;

  case 66:
#line 247 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].assignstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2095 "pascal.cpp"
    break;

  case 67:
#line 248 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].procstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2101 "pascal.cpp"
    break;

  case 68:
#line 249 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].compoundstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2107 "pascal.cpp"
    break;

  case 69:
#line 250 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].ifstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2113 "pascal.cpp"
    break;

  case 70:
#line 251 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].repeatstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2119 "pascal.cpp"
    break;

  case 71:
#line 252 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].whilestmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2125 "pascal.cpp"
    break;

  case 72:
#line 253 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].forstmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2131 "pascal.cpp"
    break;

  case 73:
#line 254 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].casestmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2137 "pascal.cpp"
    break;

  case 74:
#line 255 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].gotostmt)); (yyval.stmt)->set_anchor((yyvsp[-2].num));}
#line 2143 "pascal.cpp"
    break;

  case 75:
#line 256 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].assignstmt));}
#line 2149 "pascal.cpp"
    break;

  case 76:
#line 257 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].procstmt));}
#line 2155 "pascal.cpp"
    break;

  case 77:
#line 258 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].compoundstmt));}
#line 2161 "pascal.cpp"
    break;

  case 78:
#line 259 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].ifstmt));}
#line 2167 "pascal.cpp"
    break;

  case 79:
#line 260 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].repeatstmt));}
#line 2173 "pascal.cpp"
    break;

  case 80:
#line 261 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].whilestmt));}
#line 2179 "pascal.cpp"
    break;

  case 81:
#line 262 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].forstmt));}
#line 2185 "pascal.cpp"
    break;

  case 82:
#line 263 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].casestmt));}
#line 2191 "pascal.cpp"
    break;

  case 83:
#line 264 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.stmt)=new Statement((yyvsp[0].gotostmt));}
#line 2197 "pascal.cpp"
    break;

  case 84:
#line 266 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.assignstmt)=new AssignStmt((yyvsp[-2].idd), (yyvsp[0].texpression));}
#line 2203 "pascal.cpp"
    break;

  case 85:
#line 267 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.assignstmt)=new AssignStmt((yyvsp[-5].idd),(yyvsp[-3].texpression),(yyvsp[0].texpression));}
#line 2209 "pascal.cpp"
    break;

  case 86:
#line 269 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.procstmt)=new ProcStmt((yyvsp[0].idt));}
#line 2215 "pascal.cpp"
    break;

  case 87:
#line 270 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.procstmt)=new ProcStmt((yyvsp[-3].idt), (yyvsp[-1].argslist));}
#line 2221 "pascal.cpp"
    break;

  case 88:
#line 271 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.procstmt)=new ProcStmt((yyvsp[0].sysproc));}
#line 2227 "pascal.cpp"
    break;

  case 89:
#line 272 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.procstmt)=new ProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].exprlist));}
#line 2233 "pascal.cpp"
    break;

  case 90:
#line 273 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.procstmt)=new ProcStmt((yyvsp[-3].sysproc), (yyvsp[-1].tfactor));}
#line 2239 "pascal.cpp"
    break;

  case 91:
#line 275 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.ifstmt)=new IfStmt((yyvsp[-3].texpression),(yyvsp[-1].stmt),(yyvsp[0].elseclause));}
#line 2245 "pascal.cpp"
    break;

  case 92:
#line 277 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.elseclause)=new ElseClause((yyvsp[0].stmt));}
#line 2251 "pascal.cpp"
    break;

  case 93:
#line 278 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.elseclause)=new ElseClause();}
#line 2257 "pascal.cpp"
    break;

  case 94:
#line 280 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.repeatstmt)=new RepeatStmt((yyvsp[-2].stmtlst),(yyvsp[0].texpression));}
#line 2263 "pascal.cpp"
    break;

  case 95:
#line 282 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.whilestmt)=new WhileStmt((yyvsp[-2].texpression),(yyvsp[0].stmt));}
#line 2269 "pascal.cpp"
    break;

  case 96:
#line 284 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.forstmt)=new ForStmt((yyvsp[-6].idd),(yyvsp[-4].texpression),(yyvsp[-2].texpression),(yyvsp[0].stmt),ForStmt::TO);}
#line 2275 "pascal.cpp"
    break;

  case 97:
#line 285 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.forstmt)=new ForStmt((yyvsp[-6].idd),(yyvsp[-4].texpression),(yyvsp[-2].texpression),(yyvsp[0].stmt),ForStmt::DOWNTO);}
#line 2281 "pascal.cpp"
    break;

  case 98:
#line 287 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.casestmt)=new CaseStmt((yyvsp[-3].texpression), (yyvsp[-1].caseexprlst));}
#line 2287 "pascal.cpp"
    break;

  case 99:
#line 289 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.caseexprlst)=(yyvsp[-1].caseexprlst); (yyval.caseexprlst)->add((yyvsp[0].caseexpr));}
#line 2293 "pascal.cpp"
    break;

  case 100:
#line 290 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.caseexprlst)=new CaseExprList(); (yyval.caseexprlst)->add((yyvsp[0].caseexpr));}
#line 2299 "pascal.cpp"
    break;

  case 101:
#line 292 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.caseexpr)=new CaseExpr((yyvsp[-3].constv), (yyvsp[-1].stmt));}
#line 2305 "pascal.cpp"
    break;

  case 102:
#line 293 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.caseexpr)=new CaseExpr((yyvsp[-3].idd), (yyvsp[-1].stmt));}
#line 2311 "pascal.cpp"
    break;

  case 103:
#line 295 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.gotostmt)=new GotoStmt((yyvsp[0].num));}
#line 2317 "pascal.cpp"
    break;

  case 104:
#line 297 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.exprlist)=(yyvsp[-2].exprlist); (yyval.exprlist)->add((yyvsp[0].texpression));}
#line 2323 "pascal.cpp"
    break;

  case 105:
#line 298 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.exprlist)=new ExprList(); (yyval.exprlist)->add((yyvsp[0].texpression));}
#line 2329 "pascal.cpp"
    break;

  case 106:
#line 300 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.argslist)=(yyvsp[-2].argslist); (yyval.argslist)->add((yyvsp[0].texpression));}
#line 2335 "pascal.cpp"
    break;

  case 107:
#line 301 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.argslist)=new ArgsList(); (yyval.argslist)->add((yyvsp[0].texpression));}
#line 2341 "pascal.cpp"
    break;

  case 108:
#line 303 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::GE, (yyvsp[0].texpr));}
#line 2347 "pascal.cpp"
    break;

  case 109:
#line 304 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::GT, (yyvsp[0].texpr));}
#line 2353 "pascal.cpp"
    break;

  case 110:
#line 305 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::LE, (yyvsp[0].texpr));}
#line 2359 "pascal.cpp"
    break;

  case 111:
#line 306 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::LT, (yyvsp[0].texpr));}
#line 2365 "pascal.cpp"
    break;

  case 112:
#line 307 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::EQ, (yyvsp[0].texpr));}
#line 2371 "pascal.cpp"
    break;

  case 113:
#line 308 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[-2].texpression), Expression::NE, (yyvsp[0].texpr));}
#line 2377 "pascal.cpp"
    break;

  case 114:
#line 309 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpression)=new Expression((yyvsp[0].texpr));}
#line 2383 "pascal.cpp"
    break;

  case 115:
#line 311 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::PULS, (yyvsp[0].tterm));}
#line 2389 "pascal.cpp"
    break;

  case 116:
#line 312 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::MINUS, (yyvsp[0].tterm));}
#line 2395 "pascal.cpp"
    break;

  case 117:
#line 313 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpr)=new Expr((yyvsp[-2].texpr), Expr::OR, (yyvsp[0].tterm));}
#line 2401 "pascal.cpp"
    break;

  case 118:
#line 314 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.texpr)=new Expr((yyvsp[0].tterm));}
#line 2407 "pascal.cpp"
    break;

  case 119:
#line 316 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MUL, (yyvsp[0].tfactor));}
#line 2413 "pascal.cpp"
    break;

  case 120:
#line 317 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::DIV, (yyvsp[0].tfactor));}
#line 2419 "pascal.cpp"
    break;

  case 121:
#line 318 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::DIV, (yyvsp[0].tfactor));}
#line 2425 "pascal.cpp"
    break;

  case 122:
#line 319 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MOD, (yyvsp[0].tfactor));}
#line 2431 "pascal.cpp"
    break;

  case 123:
#line 320 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::MOD, (yyvsp[0].tfactor));}
#line 2437 "pascal.cpp"
    break;

  case 124:
#line 321 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[-2].tterm), Term::AND, (yyvsp[0].tfactor));}
#line 2443 "pascal.cpp"
    break;

  case 125:
#line 322 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tterm)=new Term((yyvsp[0].tfactor));}
#line 2449 "pascal.cpp"
    break;

  case 126:
#line 324 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[-3].idt),(yyvsp[-1].argslist));}
#line 2455 "pascal.cpp"
    break;

  case 127:
#line 325 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[0].constv));}
#line 2461 "pascal.cpp"
    break;

  case 128:
#line 326 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[-1].texpression));}
#line 2467 "pascal.cpp"
    break;

  case 129:
#line 327 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[0].tfactor), Factor::NOT_FACTOR);}
#line 2473 "pascal.cpp"
    break;

  case 130:
#line 328 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[0].tfactor), Factor::MINUS_FACTOR);}
#line 2479 "pascal.cpp"
    break;

  case 131:
#line 329 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[-3].idd), (yyvsp[-1].texpression));}
#line 2485 "pascal.cpp"
    break;

  case 132:
#line 330 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.tfactor)=new Factor((yyvsp[0].idd));}
#line 2491 "pascal.cpp"
    break;

  case 133:
#line 332 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.sysproc)=new SysProc(SysProc::READ);}
#line 2497 "pascal.cpp"
    break;

  case 134:
#line 333 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.sysproc)=new SysProc(SysProc::WRITE);}
#line 2503 "pascal.cpp"
    break;

  case 135:
#line 334 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"
    {(yyval.sysproc)=new SysProc(SysProc::WRITELN);}
#line 2509 "pascal.cpp"
    break;


#line 2513 "pascal.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 335 "/Users/chenzhuo/work/Awesome-Pascal-Compiler/src/parser/pascal.y"


//int main() {
//    yyparse();
//    return 0;
//}

// int yyerror(char * s){ printf("%s\n",s); return 0; }
