#include "sem.h"
#include "ast/ast.h"
#include "gen/code_generator.h"

/* ------------ Semantic Struct ------------ */
namespace sem {
	std::string RECORD_FIRST_NAME = "$record_";
	SemType *Entity_List[20] = {nullptr};
}

void sem::Init(){
	for(int i=0;i<sem::CONST;i++){
		sem::Entity_List[i] = new SemType(i);
		sem::Entity_List[i+sem::CONST] = new SemType(i,true);
	}
	return;
}

void sem::SemType::display(){
    std::string TYPES_MAP[8]={"int","real","char","string","bool","array","range","record"};
    std::cout << TYPES_MAP[this->type];
    if (this->is_const)
        std::cout << " const" << std::endl;
    else
        std::cout << " not const" << std::endl;
    return;
}

void sem::SemanticAnalyzer::display(){
	std::cout << "======= SEM OF "<< name <<" =======" << std::endl;
	std::map<std::string, sem::SemType *>::iterator iter;
	std::cout <<"All Types"<< std::endl;
	for (iter = types.begin();iter !=  types.end();iter++){
		std::cout << "new name:" << iter->first << " type:";
		iter->second->display();
	}
	std::cout <<"All Vars"<< std::endl;
	for (iter = vars.begin();iter !=  vars.end();iter++){
		std::cout << "new name:" << iter->first << " type:";
		iter->second->display();
	}
	std::cout << "======= end =======" << std::endl;
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
	return; // 部分结点不需要，直接返回即可
}


void ConstExpr::sem_analyze(sem::SemanticAnalyzer *ca) {
	/* 类型检查 */
	/* 维护语义 */
	std::string &const_name = id->idt;
	sem::SemType *const_type = nullptr;
	// 由于ast和sem设计出入，这里做了一次类型所对应的数字映射
	if (const_value->type == ConstValue::INTEGER) {
		const_type = sem::Entity_List[sem::INT+sem::CONST];
	} else if (const_value->type == ConstValue::REAL) {
		const_type = sem::Entity_List[sem::REAL+sem::CONST];
	} else if (const_value->type == ConstValue::CHAR) {
		const_type = sem::Entity_List[sem::CHAR+sem::CONST];
	} else if (const_value->type == ConstValue::STRING) {
//		ret = new llvm::StringLiteral(const_value->str);
	} else if (const_value->type == ConstValue::MAXINT) {
		const_type = sem::Entity_List[sem::INT+sem::CONST];
	} else if (const_value->type == ConstValue::TRUE || const_value->type == ConstValue::FALSE) {
		const_type = sem::Entity_List[sem::BOOL+sem::CONST];
	}
	ca->vars[const_name] = const_type;
}

// / 测试用
// int main(){
//     sem::SemType A(sem::INT);
//     A.display();
//     sem::SemType *p = new sem::Array(0,5,&A);
//     p->display();
//     delete p;
//     // sem::Array B(0,5,&A);
//     // std::cout << TYPES_MAP[B.type] << " " << TYPES_MAP[B.el_type->type] << std::endl;
//     return 0;
// }
