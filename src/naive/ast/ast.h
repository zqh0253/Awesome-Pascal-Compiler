#ifndef AST_H_ 
#define AST_H_

#include<string>
#include<vector>
#include<iostream>

class Node;
class Program;
class ProgramHeading;
class ProgramBlock;
class ID;
class Statement;
class StatementList;

class Node {
    public:
        Node(){}
        ~Node() {}

        bool is_leaf, is_root;
        std::string name;

        virtual std::vector<Node *> get_descendants() = 0;
        void prt();
};

class Program : public Node {
    public:
        Program(ProgramHeading* ph, ProgramBlock* pb): program_heading(ph), program_block(pb) {
            this->is_leaf = false;
            this->name = "Program";
        }
        ~Program(){}

        ProgramHeading * program_heading;
        ProgramBlock * program_block;

        std::vector<Node *> get_descendants();
};

class ProgramHeading : public Node {
    public:
        ProgramHeading(ID * id) : program_ID(id) {
            this->is_leaf = false;
            this->name = "ProgramHeading";
        }
        ~ProgramHeading(){}

        ID * program_ID;

        std::vector<Node *> get_descendants();
};

class ProgramBlock : public Node {
    public:
        ProgramBlock(StatementList * stml): statement_list(stml) {
            this->is_leaf = false;
            this->name = "ProgramBlock";
        }
        ~ProgramBlock() {}

        StatementList * statement_list;

        std::vector<Node *> get_descendants();
};

class ID : public Node {
    public:
        ID (std::string _id) : id(_id) {
            this->is_leaf = true;
            this->name = "ID";
        }
        ~ID() {}

        std::string id;

        std::vector<Node *> get_descendants();
};

class Statement : public Node {
    public:
        Statement () {}
        Statement (ID * id) : sid(id) {
            this->is_leaf = false;
            this->name = "Statement";
        }
        ~Statement () {}

        ID * sid; 

        std::vector<Node *> get_descendants();
};

class StatementList : public Statement {
    public:
        StatementList () {
            this->is_leaf = false;
            this->name = "StatementList";
        }
        ~StatementList() {}

        std::vector<Statement *> statement_list;

        void add_statement(Statement * stm);
        std::vector<Node *> get_descendants();
};

#endif