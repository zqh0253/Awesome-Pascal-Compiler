#include "ast.h"

int main(){
    std::string s1 = "s1";
    ID id1(s1);
    Statement sm(&id1);
    StatementList stml;
    stml.add_statement(&sm);
    ProgramBlock pb(&stml);

    std::string s2 = "s2";
    ID id2(s2);
    ProgramHeading ph(&id2);
    
    Program p(&ph, &pb);
    p.prt(0);
}