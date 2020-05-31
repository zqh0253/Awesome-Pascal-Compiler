#include "ast.h"
#include "gen/code_generator.h"

#define TAB(n) for (int i=0;i<n;i++) std::cout<<" "

void Node::prt(int step){
    TAB(step);
    std::cout << this->name << std::endl;
    if (this->is_leaf) return; 
    //TAB(step);
    //std::cout << "{" << std::endl;
    for (auto desc : this->get_descendants()){
        desc->prt(step + 1);
    }
    //TAB(step);
    //std::cout << "}" << std::endl;
}

std::vector<Node *> Program::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->program_heading);
    list.push_back(this->routine);
    return list;
}

std::string &Program::get_program_name() {
	return program_heading->program_ID->idt;
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
    // else if (this->type == SimpleType::IDLIST)
    //     list.push_back(this->id_list);
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
//    list.push_back(simple_type);
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
    for (auto i : this->func_and_proc)
        list.push_back(i);
    return list;
}

void RoutinePart::add(SubProgram * sp){
    this->func_and_proc.push_back(sp);
}

std::vector<Node *> SubProgram::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->head);
    list.push_back(this->routine);
    return list;
}

std::vector<Node *> SubProgramHead::get_descendants(){
	std::vector<Node *> list;
	list.push_back(this->id);
	list.push_back(this->parameters);
	if (this->type == SubProgramHead::FUNCTION) list.push_back(this->simple_type);
	return list;
}

std::vector<Node *> Parameters::get_descendants(){
    std::vector<Node *> list;
    if (!this->is_leaf) list.push_back(this->para_dec_list);
    return list;
}

std::vector<Node *> ParaDecList::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->para_dec_list)
        list.push_back(i);
    return list;
}

void ParaDecList::add(ParaTypeList * ptl){
    this->para_dec_list.push_back(ptl);
}

std::vector<Node *> ParaTypeList::get_descendants(){
    std::vector<Node *> list;
    list.push_back(id_list);
    list.push_back(simple_type);
    return list;
}

std::vector<Node *> RoutineBody::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->compound_stmt);
    return list;
}

std::vector<Node *> CompoundStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->stmt_list);
    return list;
}

std::vector<Node *> StatementList::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->stmt_list)
        list.push_back(i);
    return list;
}

void StatementList::add(Statement * s){
    this->stmt_list.push_back(s);
}

std::vector<Node *> Statement::get_descendants(){
    std::vector<Node *> list;
    if (this->type==ASSIGN)
        list.push_back(this->assign_stmt);
    else if (this->type==PROC)
        list.push_back(this->proc_stmt);
    else if (this->type==COMPOUND)
        list.push_back(this->compound_stmt);
    else if (this->type==IF)
        list.push_back(this->if_stmt);
    else if (this->type==REPEAT)
        list.push_back(this->repeat_stmt);
    else if (this->type==WHILE)
        list.push_back(this->while_stmt);
    else if (this->type==FOR)
        list.push_back(this->for_stmt);
    else if (this->type==CASE)
        list.push_back(this->case_stmt);
    else list.push_back(this->goto_stmt);
    return list;
}

void Statement::set_anchor(int a){
    this->anchor = a;
}

std::vector<Node *> CaseStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->expr);
    list.push_back(this->case_expr_list);
    return list;
}

std::vector<Node *> CaseExprList::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->case_expr_list)
        list.push_back(i);
    return list;
}

void CaseExprList::add(CaseExpr * c){
    this->case_expr_list.push_back(c);
}

std::vector<Node *> CaseExpr::get_descendants(){
    std::vector<Node *> list;
    if (this->type==CaseExpr::CONST){
        list.push_back(this->const_value);
    }
    else{
        list.push_back(this->idd);
    }
    list.push_back(this->stmt);
    return list;
}

std::vector<Node *> GotoStmt::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> AssignStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->idd);
    list.push_back(this->e1);
    if (this->type == AssignStmt::ARRAY)
        list.push_back(this->e2);
    return list;
}

std::vector<Node *> ProcStmt::get_descendants(){
    std::vector<Node *> list;
    if (this->type==ProcStmt::SINGLE_ID)
        list.push_back(this->id);
    else if (this->type==ProcStmt::ID_WITH_ARGS){
        list.push_back(this->id);
        list.push_back(this->args_list);
    }
    else if (this->type==ProcStmt::SYS_PROC){
        list.push_back(this->sys_proc);
    }
    else if (this->type==ProcStmt::SYS_PROC_WITH_EXPR){
        list.push_back(this->sys_proc);
        list.push_back(this->expr_list);
    }
    else {
        list.push_back(this->sys_proc);
        list.push_back(this->factor);
    }
    return list;
}

std::vector<Node *> IfStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->expr);
    list.push_back(this->stmt);
    list.push_back(this->else_clause);
    return list;
}

std::vector<Node *> ElseClause::get_descendants(){
    std::vector<Node *> list;
    if (!this->is_leaf)
        list.push_back(this->stmt);
    return list;
}

std::vector<Node *> RepeatStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->stmt_list);
    list.push_back(this->expr);
    return list;
}

std::vector<Node *> WhileStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->expr);
    list.push_back(this->stmt);
    return list;
}

std::vector<Node *> ForStmt::get_descendants(){
    std::vector<Node *> list;
    list.push_back(this->idd);
    list.push_back(this->expr1);
    list.push_back(this->expr2);
    list.push_back(this->stmt);
    return list;
}

std::vector<Node *> SysProc::get_descendants(){
    std::vector<Node *> list;
    return list;
}

std::vector<Node *> IDDotted::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->id_list)
        list.push_back(i);
    return list;
}

void IDDotted::add(ID * i){
    this->id_list.push_back(i);
}

std::vector<Node *> Expression::get_descendants(){
    std::vector<Node *> list;
    if (this->op!= Expression::SINGLE){
        list.push_back(this->expression);
    }
    list.push_back(this->expr);
    return list;
}

std::vector<Node *> Expr::get_descendants(){
    std::vector<Node *> list;
    if (this->op!= Expr::SINGLE){
        list.push_back(this->expr);
    }
    list.push_back(this->term);
    return list;
}

std::vector<Node *> Term::get_descendants(){
    std::vector<Node *> list;
    if (this->op!= Term::SINGLE){
        list.push_back(term);
    }
    list.push_back(factor);
    return list;
}

std::vector<Node *> Factor::get_descendants(){
    std::vector<Node *> list;
    if (this->type == Factor::FUNC_WITH_NO_ARGS)
        list.push_back(this->id1);
    else if (this->type == Factor::FUNC){
        list.push_back(this->id1);
        list.push_back(this->args_list);
    }
    else if (this->type == Factor::CONST_VALUE){
        list.push_back(this->const_value);
    }
    else if (this->type == Factor::EXPRESSION){
        list.push_back(this->expr);
    }
    else if (this->type == Factor::ARRAY){
        list.push_back(this->idd);
        list.push_back(this->expr);
    }
    else if (this->type == Factor::MEMBER){
        list.push_back(this->idd);
    }
    else if (this->type == Factor::ADDR){
	    list.push_back(this->idd);
    }
    else if (this->type == Factor::ASTERISK){
	    list.push_back(this->idd);
    }
    else {
        list.push_back(this->factor);
    }
    return list;
}

std::vector<Node *> ArgsList::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->args_list)
        list.push_back(i);
    return list;
}

void ArgsList::add(Expression * e){
    this->args_list.push_back(e);
}


std::vector<Node *> ExprList::get_descendants(){
    std::vector<Node *> list;
    for (auto i : this->expr_list)
        list.push_back(i);
    return list;
}

void ExprList::add(Expression * e){
    this->expr_list.push_back(e);
}


