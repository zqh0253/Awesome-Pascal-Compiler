#include "ast.h"

#define TAB(n) for (int i=0;i<n;i++) std::cout<<"\t"

void Node::prt(int step){
    TAB(step);
    std::cout << this->name << std::endl;
    if (this->is_leaf) return; 
    TAB(step);
    std::cout << "{" << std::endl;
    for (auto desc : this->get_descendants()){
        desc->prt(step + 1);
    }
    TAB(step);
    std::cout << "}" << std::endl;
}

std::vector<Node *> Program::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->program_heading);
    list.push_back(this->routine);
    return list;
}

std::vector<Node *> ID::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> IDList::get_descendants(){
    std::vector<Node *> list;
    for (auto id:ID_list)
        list.push_back(id);
    return list;
}

void IDList::add(ID * id){
    ID_list.push_back(id);
}


std::vector<Node *> ProgramHeading::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->program_ID);
    return list;
}

std::vector<Node *> Routine::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->routine_head);
    list.push_back(this->routine_body);
    return list;
}

std::vector<Node *> RoutineHead::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->label_part);
    list.push_back(this->const_part);
    list.push_back(this->type_part);
    list.push_back(this->var_part);
    list.push_back(this->routine_part);
    return list;
}

std::vector<Node *> LabelPart::get_descendants(){
    std::vector<Node *> list;
    return list;
}


std::vector<Node *> ConstPart::get_descendants(){
    std::vector<Node *> list;
    if (!this->is_leaf) list.push_back(this->const_expr_list);
    return list;
}

std::vector<Node *> ConstExprList::get_descendants(){
    std::vector<Node *> list;
    for(auto ce : this->const_expr_list)
        list.push_back(ce);
    return list;
}

void ConstExprList::add(ConstExpr * ce){
    this->const_expr_list.push_back(ce);
}

std::vector<Node *> ConstExpr::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->id);
    list.push_back(this->const_value);
    return list;
}

std::vector<Node *> ConstValue::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> TypePart::get_descendants(){
    std::vector<Node *> list;
    if(!this->is_leaf) list.push_back(this->type_dec_list);
    return list;
}

std::vector<Node *> TypeDecList::get_descendants(){
    std::vector<Node *> list;
    for (auto td : this->type_definition_list)
        list.push_back(td);
    return list;
}

void TypeDecList::add(TypeDef * td){
    this->type_definition_list.push_back(td);
}

std::vector<Node *> TypeDef::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->id);
    list.push_back(this->type_dec);
    return list;
}

std::vector<Node *> TypeDec::get_descendants(){
    std::vector<Node *> list;
    if (this->type == TypeDec::SIMPLE)
        list.push_back(this->simple_type);
    else if (this->type == TypeDec::ARRAY)
        list.push_back(this->array_type);
    else
        list.push_back(this->record_type);
    return list;
}

std::vector<Node *> SimpleType::get_descendants(){
    std::vector<Node *> list;
    if (this->type == SimpleType::SYS_TYPE)
        list.push_back(this->sys_type);
    else if (this->type == SimpleType::IDENTIFY)
        list.push_back(this->id);
    else if (this->type == SimpleType::IDLIST)
        list.push_back(this->id_list);
    else if (this->type == SimpleType::RANGE)
        list.push_back(this->range_type);
    return list;
}

std::vector<Node *> SysType::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> RangeType::get_descendants(){
    std::vector<Node *> list;
    if (this->type == RangeType::IDENTIFY){
        list.push_back(left_id);
        list.push_back(right_id);
    }
    else {
        list.push_back(left_const);
        list.push_back(right_const);
    }
        
    return list;
}

std::vector<Node *> ArrayType::get_descendants(){
    std::vector<Node *> list;
    list.push_back(simple_type);
    list.push_back(type_dec);
    return list;
}

std::vector<Node *> RecordType::get_descendants(){
    std::vector<Node *> list;
    list.push_back(record_dec_list);
    return list;
}

std::vector<Node *> VarPart::get_descendants(){
    std::vector<Node *> list;
    if (!is_leaf)
        list.push_back(var_dec_list);
    return list;
}

std::vector<Node *> VarDecList::get_descendants(){
    std::vector<Node *> list;
    for (auto vd : this->var_dec_list)
        list.push_back(vd);
    return list;
}

void VarDecList::add(VarDec * vd){
    this->var_dec_list.push_back(vd);
}

std::vector<Node *> VarDec::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->id_list);
    list.push_back(this->type_dec);
    return list;
}

std::vector<Node *> RoutinePart::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> RoutineBody::get_descendants(){
    std::vector<Node *> list;
    return list;
}


