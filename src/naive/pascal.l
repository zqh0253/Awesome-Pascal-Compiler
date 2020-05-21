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


REV_PROGRAM program

OP_SEMICOLON ";"

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

{REV_PROGRAM} {return REV_PROGRAM;}

{OP_SEMICOLON} {return OP_SEMICOLON;}

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