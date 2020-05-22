#include "ast.h"

void Node::prt(){
    std::cout << this->name << std::endl;
    if (this->is_leaf) return; 
    std::cout << "{" << std::endl;
    for (auto desc : this->get_descendants()){
        desc->prt();
    }
    std::cout << "}" << std::endl;
}

std::vector<Node *> Program::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->program_heading);
    list.push_back(this->program_block);
    return list;
}

std::vector<Node *> ProgramHeading::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->program_ID);
    return list;
}

std::vector<Node *> ProgramBlock::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->statement_list);
    return list;
}

std::vector<Node *> ID::get_descendants(){
    std::vector<Node *> list;
    return list;
}


std::vector<Node *> Statement::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->sid);
    return list;
}

std::vector<Node *> StatementList::get_descendants(){
    std::vector<Node *> list;
    for (auto stm : this->statement_list)
        list.push_back(stm);
    return list;
}

void StatementList::add_statement(Statement * stm){
    this->statement_list.push_back(stm);
}