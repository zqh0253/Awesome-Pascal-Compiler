#include "sem.h"
#include "ast/ast.h"
#include "gen/code_generator.h"

namespace sem {
	std::string RECORD_FIRST_NAME = "$record_";
	SemType *IntTy = new SemType(INT);
	SemType *VoidTy = new SemType(VOID);
	SemType *RealTy = new SemType(REAL);
	SemType *BoolTy = new SemType(BOOL);
	SemType *CharTy = new SemType(CHAR);
	SemType *ConstIntTy = new SemType(INT, true);
	SemType *ConstVoidTy = new SemType(VOID, true);
	SemType *ConstRealTy = new SemType(REAL, true);
	SemType *ConstBoolTy = new SemType(BOOL, true);
	SemType *ConstCharTy = new SemType(CHAR, true);
}

void sem::SemType::display(){
    std::string TYPES_MAP[8]={"int","real","char","string","bool","array","range","record"};
    std::cout << "type is " << TYPES_MAP[this->type] << std::endl;
    if (this->is_const)
        std::cout << "var is const" << std::endl;
    else
        std::cout << "var is not const" << std::endl;
    return;
}

std::string sem::Record::global_name() {
	return local->global_name(type_name);
}

sem::SemanticAnalyzer *sem::SemanticAnalyzer::last_sem() {
	return cg->get_block(level-1)->sa;
}

sem::SemanticAnalyzer *sem::SemanticAnalyzer::global_sem() {
	return cg->global_sem();
}


/* ------------ Semantic Analyze ------------ */
void Node::sem_analyze(sem::SemanticAnalyzer *ca) {

}


void ConstExpr::sem_analyze(sem::SemanticAnalyzer *ca) {
	std::string &const_name = id->idt;
	sem::SemType *const_type = nullptr;
	if (const_value->type == ConstValue::INTEGER) {
		const_type = sem::ConstIntTy;
	} else if (const_value->type == ConstValue::REAL) {
		const_type = sem::ConstRealTy;
	} else if (const_value->type == ConstValue::CHAR) {
		const_type = sem::ConstCharTy;
	} else if (const_value->type == ConstValue::STRING) {
		const_type = new sem::String(const_value->str.size(), true);
	} else if (const_value->type == ConstValue::SYSCON && const_value->sys_con == ConstValue::MAXINT) {
		const_type = sem::ConstIntTy;
	} else if (const_value->type == ConstValue::SYSCON && const_value->sys_con == ConstValue::TRUE) {
		const_type = sem::ConstBoolTy;
	} else if (const_value->type == ConstValue::SYSCON && const_value->sys_con == ConstValue::FALSE) {
		const_type = sem::ConstBoolTy;
	}
	ca->vars[const_name] = const_type;
}

