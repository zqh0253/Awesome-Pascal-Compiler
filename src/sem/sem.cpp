#include "sem.h"
#include "ast/ast.h"
#include "gen/code_generator.h"

/* ------------ Semantic Struct ------------ */
namespace sem {
	std::string RECORD_FIRST_NAME = "$record_";
	std::string STRING_FIRST_NAME = "$string_";
	std::string RANGE_FIRST_NAME = "$range_";
	std::string ARRAY_FIRST_NAME = "$array_";
	SemType *Entity_List[20] = {nullptr};
	std::map<std::string, SemType *> Global_Types;
}

void sem::Init(){
	for(int i=0;i<sem::CONST;i++){
		sem::Entity_List[i] = new SemType(i);
		sem::Entity_List[i+sem::CONST] = new SemType(i,true);
	}
	return;
}

// 待完成
// bool sem::has_exist(std::string name, sem::SemType *ret){
// 	if (sem::Global_Types.count(name)){
// 		ret = Global_Types[name];
// 		return true;
// 	}
// 	else  return false;
// }

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

sem::SemType *sem::SemanticAnalyzer::find_var(std::string name){
	if (this->vars.count(name)) return this->vars[name];
	else if(this->global_sem()->vars.count(name)) return this->global_sem()->vars[name];
	else throw sem::SemEXception("Type: variable "+name+" has not be defined!");
	return nullptr;
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
		const_type = new sem::String(const_value->str.size(), true);
	} else if (const_value->type == ConstValue::SYSCON){
		if (const_value->sys_con == ConstValue::MAXINT) {
			const_type = sem::Entity_List[sem::INT+sem::CONST];
		} else if (const_value->sys_con == ConstValue::TRUE || const_value->sys_con == ConstValue::FALSE) {
			const_type = sem::Entity_List[sem::BOOL+sem::CONST];
		}
	}
	ca->vars[const_name] = const_type;
	return;
}

void TypeDef::sem_analyze(sem::SemanticAnalyzer *ca){
	/* 类型检查 */
	/* 维护语义 */
	ca->types[id->idt] = type_dec->sem_type;
	return;
}

void TypeDec::sem_analyze(sem::SemanticAnalyzer *ca){
	/* 类型检查 */
	/* 维护语义 */
	if (type == TypeDec::SIMPLE){
		sem_type = simple_type->sem_type;
	}
	else if (type == TypeDec::ARRAY){
		sem_type = array_type->sem_type;
	}
	else if (type == TypeDec::RECORD){
		sem_type = record_type->sem_type;
	}
	return;
}

void SimpleType::sem_analyze(sem::SemanticAnalyzer *ca){
	sem_type = nullptr;
	if (type == SimpleType::SYS_TYPE){
		/* 类型检查 */
		/* 维护语义 */
		if(sys_type->type == SysType::INTEGER){
			sem_type = sem::Entity_List[sem::INT];
		}
		else if(sys_type->type == SysType::REAL){
			sem_type = sem::Entity_List[sem::REAL];
		}
		else if(sys_type->type == SysType::CHAR){
			sem_type = sem::Entity_List[sem::CHAR];
		}
		else if(sys_type->type == SysType::BOOLEAN){
			sem_type = sem::Entity_List[sem::BOOL];
		}
		else if(sys_type->type == SysType::STRING){
			sem_type = sem::Entity_List[sem::STRING];
		}
	}
	else if(type == SimpleType::IDENTIFY){
		sem_type = ca->find_var(id->idt);
	}
	else if(type == SimpleType::IDLIST){
		for(std::vector<ID *>::size_type i=0;i!=id_list->ID_list.size();i++){
			if(id_list->ID_list[i] == id_list->ID_list[0]){
				if (i==0) sem_type = ca->find_var(id_list->ID_list[0]->idt);
			}
			else throw sem::SemEXception("Type: "+id_list->name+" are not the same!");
		}
	}
	else if(type == SimpleType::RANGE){
		// 这里也许需要存变量的值
		// if (range_type->type == RangeType::IDENTIFY){
		// 	ca->find_var(range_type->left_id->idt);
		// 	ca->find_var(range_type->right_id->idt);
		// 	sem_type = new sem::Range(left_id->)
		// }else
		if (range_type->type == RangeType::CONST){
			if (range_type->left_const->type != ConstValue::INTEGER || range_type->right_const->type != ConstValue::INTEGER)
				throw sem::SemEXception("Type: Range can only be defined by inerger!");
			sem_type = new sem::Range(range_type->left_const->integer,range_type->right_const->integer);
		}
	}
	return;
}

void ArrayType::sem_analyze(sem::SemanticAnalyzer *ca){
	// 似乎只能用range定义
	if (simple_type->type == SimpleType::RANGE){
		sem::Range* de = (sem::Range*)simple_type->sem_type;
		sem_type = new sem::Array( de->begin, de->end, type_dec->sem_type);
	}
	else{
		throw sem::SemEXception("Type: Array can only be defined by range!");
	}
	return;
}

void RecordType::sem_analyze(sem::SemanticAnalyzer *ca){
	std::string re_name = sem::RECORD_FIRST_NAME + std::to_string(ca->num++);
	sem_type = new sem::Record(re_name,ca);
	sem::Record *re = (sem::Record*)sem_type;
	for(std::vector<VarDec *>::size_type i=0;i!=record_dec_list->var_dec_list.size();i++){
		VarDec *temp = record_dec_list->var_dec_list[i];
		std::vector<std::string> names;
		if (temp->type_dec->sem_type == nullptr)
				throw sem::SemEXception("Def: Type "+temp->type_dec->name+" is not exist!");
		for(std::vector<ID *>::size_type j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			if (std::find(names.begin(),names.end(),name) != names.end())
				throw sem::SemEXception("Def: Variable name "+name+" in record \""+ re_name +"\" has a conflict!");
			else {
				re->types.push_back(make_pair(name,temp->type_dec->sem_type));
			}
			names.push_back(name);
		}
	}
	ca->types[re_name] = sem_type;
	return;
}

void VarPart::sem_analyze(sem::SemanticAnalyzer *ca){
	for(std::vector<VarDec *>::size_type i=0;i!=var_dec_list->var_dec_list.size();i++){
		VarDec *temp = var_dec_list->var_dec_list[i];
		if (temp->type_dec->sem_type == nullptr)
				throw sem::SemEXception("Def: Type "+temp->type_dec->name+" is not exist!");
		for(std::vector<ID *>::size_type j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			if (ca->vars.count(name))
				throw sem::SemEXception("Def: Variable name "+name+" has a conflict!");
			else ca->vars[name] = temp->type_dec->sem_type;
		}
	}
	return;
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
