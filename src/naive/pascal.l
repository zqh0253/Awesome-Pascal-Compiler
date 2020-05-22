%option noyywrap yylineno caseless

%{
#include <cstring>

#include "ast/ast.h"
#include "pascal.hpp"

int yycolumn = 1;
#define YY_USER_ACTION  yylloc.first_line = yylloc.last_line = yylineno; \
                        yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
                        yycolumn += yyleng;

void yyerror(const char *s);

// void copy_str(char *str, int len) {
//     int l = (len >= MAX_STR_LEN ? MAX_STR_LEN - 1 : len);
//     strncpy(yylval.str, str, l);
//     yylval.str[l] = 0;
// }
%}


REV_PROGRAM "program"

OP_SEMICOLON ";"

IDT [a-zA-Z_][a-zA-Z0-9_]*

COMMENT "{"[^\}]*"}"

%%

{REV_PROGRAM} {return REV_PROGRAM;}

{OP_SEMICOLON} {return OP_SEMICOLON;}


{IDT} {
    std::string context = yytext;
    yylval.idt = new ID(context);
    return IDT;
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
