%option noyywrap yylineno caseless

%{
#include <cstring>

#include "pascal.y.hpp"

int yycolumn = 1;
#define YY_USER_ACTION  yylloc.first_line = yylloc.last_line = yylineno; \
                        yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
                        yycolumn += yyleng;

void copy_str(char *str, int len) {
    int l = (len >= MAX_STR_LEN ? MAX_STR_LEN - 1 : len);
    strncpy(yylval.str, str, l);
    yylval.str[l] = 0;
}
%}

REV_AND and
REV_ARRAY array
REV_BEGIN begin
REV_BREAK break
REV_CASE case
REV_CONST const
REV_CONTINUE continue
REV_DEFAULT default
REV_DIV div
REV_DO do
REV_DOWNTO downto
REV_ELSE else
REV_END end
REV_EXIT exit
REV_FILE file
REV_FOR for
REV_FORWARD forward
REV_FUNCTION function
REV_GOTO goto
REV_IF if
REV_IN in
REV_LABEL label
REV_MOD mod
REV_NIL nil
REV_NOT not
REV_OF of
REV_OR or
REV_PACKED packed
REV_PROCEDURE procedure
REV_PROGRAM program
REV_RECORD record
REV_REPEAT repeat
REV_SET set
REV_SIZEOF sizeof
REV_THEN then
REV_TO to
REV_TYPE type
REV_UNTIL until
REV_VAR var
REV_WHILE while
REV_WITH with
REV_XOR xor

OP_ADD "+"
OP_SUB "-"
OP_MUL "*"
OP_DIV "/"
OP_EQ "="
OP_LT "<"
OP_GT ">"
OP_LBRAC "["
OP_RBRAC "]"
OP_PERIOD "."
OP_COMMA ","
OP_COLON ":"
OP_SEMICOLON ";"
OP_AT "@"
OP_CARET "^"
OP_LPAREN "("
OP_RPAREN ")"
OP_NE "<>"
OP_LEQ "<="
OP_GEQ ">="
OP_ASSIGN ":="
OP_RANGE ".."

TYPE_INT integer|longint
TYPE_REAL real
TYPE_CHAR character|char
TYPE_BOOL boolean|bool
TYPE_STRING string

BOOL_TRUE true
BOOL_FALSE false

ID [a-zA-Z_][a-zA-Z0-9_]*

SIGN "+"|"-"
INT [0-9]+
REAL ([0-9]+\.[0-9]+)|([0-9]+\.[0-9]+e{SIGN}?[0-9]+)|([0-9]+e{SIGN}?[0-9]+)

CHAR \'.\'
ESC_CHAR \'#{INT}\'
STR \'[^']*\'

COMMENT "{"[^\}]*"}"

%%

{REV_AND} {return REV_AND;}
{REV_ARRAY} {return REV_ARRAY;}
{REV_BEGIN} {return REV_BEGIN;}
{REV_BREAK} {return REV_BREAK;}
{REV_CASE} {return REV_CASE;}
{REV_CONST} {return REV_CONST;}
{REV_CONTINUE} {return REV_CONTINUE;}
{REV_DEFAULT} {return REV_DEFAULT;}
{REV_DIV} {return REV_DIV;}
{REV_DO} {return REV_DO;}
{REV_DOWNTO} {return REV_DOWNTO;}
{REV_ELSE} {return REV_ELSE;}
{REV_END} {return REV_END;}
{REV_EXIT} {return REV_EXIT;}
{REV_FILE} {return REV_FILE;}
{REV_FOR} {return REV_FOR;}
{REV_FORWARD} {return REV_FORWARD;}
{REV_FUNCTION} {return REV_FUNCTION;}
{REV_GOTO} {return REV_GOTO;}
{REV_IF} {return REV_IF;}
{REV_IN} {return REV_IN;}
{REV_LABEL} {return REV_LABEL;}
{REV_MOD} {return REV_MOD;}
{REV_NIL} {return REV_NIL;}
{REV_NOT} {return REV_NOT;}
{REV_OF} {return REV_OF;}
{REV_OR} {return REV_OR;}
{REV_PACKED} {return REV_PACKED;}
{REV_PROCEDURE} {return REV_PROCEDURE;}
{REV_PROGRAM} {return REV_PROGRAM;}
{REV_RECORD} {return REV_RECORD;}
{REV_REPEAT} {return REV_REPEAT;}
{REV_SET} {return REV_SET;}
{REV_SIZEOF} {return REV_SIZEOF;}
{REV_THEN} {return REV_THEN;}
{REV_TO} {return REV_TO;}
{REV_TYPE} {return REV_TYPE;}
{REV_UNTIL} {return REV_UNTIL;}
{REV_VAR} {return REV_VAR;}
{REV_WHILE} {return REV_WHILE;}
{REV_WITH} {return REV_WITH;}
{REV_XOR} {return REV_XOR;}

{OP_ADD} {return OP_ADD;}
{OP_SUB} {return OP_SUB;}
{OP_MUL} {return OP_MUL;}
{OP_DIV} {return OP_DIV;}
{OP_EQ} {return OP_EQ;}
{OP_LT} {return OP_LT;}
{OP_GT} {return OP_GT;}
{OP_LBRAC} {return OP_LBRAC;}
{OP_RBRAC} {return OP_RBRAC;}
{OP_PERIOD} {return OP_PERIOD;}
{OP_COMMA} {return OP_COMMA;}
{OP_COLON} {return OP_COLON;}
{OP_SEMICOLON} {return OP_SEMICOLON;}
{OP_AT} {return OP_AT;}
{OP_CARET} {return OP_CARET;}
{OP_LPAREN} {return OP_LPAREN;}
{OP_RPAREN} {return OP_RPAREN;}
{OP_NE} {return OP_NE;}
{OP_LEQ} {return OP_LEQ;}
{OP_GEQ} {return OP_GEQ;}
{OP_ASSIGN} {return OP_ASSIGN;}
{OP_RANGE} {return OP_RANGE;}

{TYPE_INT} {return TYPE_INT;}
{TYPE_REAL} {return TYPE_REAL;}
{TYPE_CHAR} {return TYPE_CHAR;}
{TYPE_BOOL} {return TYPE_BOOL;}
{TYPE_STRING} {return TYPE_STRING;}

{BOOL_TRUE} {return BOOL_TRUE;}
{BOOL_FALSE} {return BOOL_FALSE;}



{ID} {
    copy_str(yytext, yyleng);
    return ID;
}

{INT} {
    yylval.num = atoi(yytext);
    return INT;
}
{REAL} {
    yylval.real = atof(yytext);
    return REAL;
}

{CHAR} {
    yylval.chr = yytext[1];
    return CHAR;
}
{ESC_CHAR} {
    yylval.chr = strtol(yytext + 2, NULL, 10);
    return CHAR;
}
{STR} {
    copy_str(yytext + 1, yyleng - 2);
    return STR;
}

{COMMENT} {}

\n|(\r\n) {
    yycolumn = 1;
}
" "|\t {}

. {
    printf("unknown character %d\n", (int) yytext[0]);
    return yytext[0];
}

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s (at %d:%d)\n", s, yylloc.first_line, yylloc.first_column);
}






%%
"="