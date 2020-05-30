#include "sem.h"
#include "ast/ast.h"
#include "gen/code_generator.h"

/* ------------ Semantic Struct ------------ */
namespace sem {
	const int INT = 0;
	const int REAL = 1;
	const int CHAR = 2;
	const int VOID = 3;
	const int BOOL = 4;
	const int STRING = 5;
	const int RANGE = 6;
	const int ARRAY = 7;
	const int RECORD = 8;
	const int CONST = 6;
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

void sem::SemType::display(int i){
    std::string TYPES_MAP[9]={"int","real","char","void","bool","string","range","array"};
    std::cout << TYPES_MAP[this->type];
    if (this->is_const)
        std::cout << " const" << std::endl;
    else
        std::cout << " not const" << std::endl;
    return;
}

void sem::Record::display(int i){
	std::cout << "record";
    if (this->is_const)
        std::cout << " const" << std::endl;
    else
        std::cout << " not const" << std::endl;
	for (int j=0;j<names.size();j++){
		for (int j=0;j<i;j++) std::cout << "  ";
		std::cout << "name:" << names[j] << " type:";
		types[names[j]]->display(i+1);
	}
	return;
}

void sem::SemanticAnalyzer::display(int i){
	std::cout << "======= sem of "<< name <<" =======" << std::endl;
	std::cout <<"All Types"<< std::endl;
	for (auto iter = types.begin();iter !=  types.end();iter++){
		for (int j=0;j<i;j++) std::cout << "  ";
		std::cout << "name:" << iter->first << " type:";
		iter->second->display(i+1);
	}
	std::cout <<"All Vars"<< std::endl;
	for (auto iter = vars.begin();iter !=  vars.end();iter++){
		for (int j=0;j<i;j++) std::cout << "  ";
		std::cout << "name:" << iter->first << " type:";
		iter->second->display(i+1);
	}
	std::cout << "======= end =======" << std::endl;
	return;
}

std::string sem::Record::global_name() {
	return local->to_global_name(type_name);
}

sem::SemanticAnalyzer *sem::SemanticAnalyzer::last_sem() {
	return cg->get_block(level-1)->sa;
}

sem::SemanticAnalyzer *sem::SemanticAnalyzer::global_sem() {
	return cg->global_sem();
}

sem::SemType *sem::SemanticAnalyzer::find_var(std::string &name){
	sem::SemanticAnalyzer* temp = this;
	for(temp=this; temp != this->global_sem(); temp = temp->last_sem()){
		if(temp->vars.count(name)) return temp->vars[name];
	}
	if(temp->vars.count(name)) return temp->vars[name];
	else throw sem::SemException("Var: variable " + name + " has not be defined!");
}

sem::SemType *sem::SemanticAnalyzer::find_type(std::string &name){
	sem::SemanticAnalyzer* temp = this;
	for(temp=this; temp != this->global_sem(); temp = temp->last_sem()){
		if(temp->types.count(name)) return temp->types[name];
	}
	if(temp->types.count(name)) return temp->types[name];
	else throw sem::SemException("Type: type " + name + " has not be defined!");
}

bool sem::SemanticAnalyzer::is_available(std::string &name, const std::string &e){
	if (this->vars.count(name) || this->types.count(name) || this->funcs.count(name)){
		throw sem::SemException(e);
	}
	return true;
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
	if (! ca->is_available(id->idt,("TypeDef: Type name "+id->idt+" has a conflict!"))) return;
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
		sem_type = ca->find_type(id->idt);
	}
	// else if(type == SimpleType::IDLIST){
	// 	// 可能存在一些问题，需要修改
	// 	for(std::vector<ID *>::size_type i=0;i!=id_list->ID_list.size();i++){
	// 		if(id_list->ID_list[i] == id_list->ID_list[0]){
	// 			if (i==0) sem_type = ca->find_type(id_list->ID_list[0]->idt);
	// 		}
	// 		else throw sem::SemException("Type: "+id_list->name+" are not the same!");
	// 	}
	// }
	else if(type == SimpleType::RANGE){
		// 这里也许需要存变量的值
		// if (range_type->type == RangeType::IDENTIFY){
		// 	ca->find_var(range_type->left_id->idt);
		// 	ca->find_var(range_type->right_id->idt);
		// 	sem_type = new sem::Range(left_id->)
		// }else
		if (range_type->type == RangeType::CONST){
			if (range_type->left_const->type != ConstValue::INTEGER || range_type->right_const->type != ConstValue::INTEGER)
				throw sem::SemException("Type: Range can only be defined by inerger!");
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
		throw sem::SemException("Type: Array can only be defined by range!");
	}
	return;
}

void RecordType::sem_analyze(sem::SemanticAnalyzer *ca){
	std::string re_name = sem::RECORD_FIRST_NAME + std::to_string(ca->num++);
	sem_type = new sem::Record(re_name,ca);
	sem::Record *re = (sem::Record*)sem_type;
	for(int i=0;i!=record_dec_list->var_dec_list.size();i++){
		VarDec *temp = record_dec_list->var_dec_list[i];
		// 检查类型是否存在
		if (temp->type_dec->sem_type == nullptr)
				throw sem::SemException("Def: Type " + temp->type_dec->name + " is not exist!");
		for(int j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			// 检查变量名是否冲突（record内部）
			if (std::find(re->names.begin(),re->names.end(),name) != re->names.end())
				throw sem::SemException("Def: Variable name " + name + " in record \"" + re_name + "\" has a conflict!");
			else {
				re->names.push_back(name);
				re->types[name] = temp->type_dec->sem_type;
			}
		}
	}
	ca->types[re_name] = sem_type;
	return;
}

void VarPart::sem_analyze(sem::SemanticAnalyzer *ca){
	if (is_empty) return;
	for(int i=0;i!=var_dec_list->var_dec_list.size();i++){
		VarDec *temp = var_dec_list->var_dec_list[i];
		// 检查类型是否存在
		if (temp->type_dec->sem_type == nullptr)
				throw sem::SemException("Def: Type " + temp->type_dec->name + " is not exist!");
		for(int j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			// 检查变量名是否冲突（当前语义块内部）
			if (! ca->is_available(name,("VarDef: Variable name "+name+" has a conflict!"))) return;
			else ca->vars[name] = temp->type_dec->sem_type;
		}
	}
	return;
}

void SubProgramHead::sem_analyze(sem::SemanticAnalyzer *ca){
	// 检查命名是否合法
	sem::FuncInfo *temp;
	if (! ca->is_available(id->idt, ("FuncDef: Function name "+id->idt+" has a conflict!"))) return;
	// 判断是否有参数
	if (parameters->func_info == nullptr){
		temp = new sem::FuncInfo();
	}
	else temp = parameters->func_info;
	// 判断是否有返回值
	if (simple_type == nullptr) temp->ret = sem::Entity_List[sem::VOID];
	else temp->ret = simple_type->sem_type;
	// 将返回值注册为变量，检查是否重名
	for (auto t: temp->types) {
		if (t.first == id->idt) {
			throw sem::SemException("FuncDef: parameter '" + t.first + "' conflict!");
		}
	}
	temp->types.push_back(make_pair(id->idt, temp->ret));
	// 根据函数名记录函数
	ca->funcs[id->idt] = temp;
	return;
}

void Parameters::sem_analyze(sem::SemanticAnalyzer* ca){
	if (is_empty) return;
	else{
		func_info = new sem::FuncInfo();
		std::vector<std::string> names;
		for(int i=0;i!=para_dec_list->para_dec_list.size();i++){
			ParaTypeList *temp = para_dec_list->para_dec_list[i];
			// 检查类型是否存在
			if (temp->simple_type->sem_type == nullptr)
					throw sem::SemException("Function: Type " + temp->simple_type->id->idt + " is not exist!");
			for(int j=0; j != temp->id_list->ID_list.size();j++){
				std::string name = temp->id_list->ID_list[j]->idt;
				// 检查变量名是否冲突（function内部）
				if (std::find(names.begin(),names.end(),name) != names.end())
					throw sem::SemException("Function: Variable name " + name + " in parameters has a conflict!");
				else {
					func_info->types.push_back(make_pair(name,temp->simple_type->sem_type));
				}
				names.push_back(name);
			}
		}
	}
}

void AssignStmt::sem_analyze(sem::SemanticAnalyzer* ca){
	// 需要判定左右是否一样
	sem::SemType *check;
	int n = idd->id_list.size()-1;
	std::string name = idd->id_list[n]->idt;
	// 建立左值结构
	check = ca->find_var(name);
	left_value = new sem::LeftValue(name,check);
	// 当n=0，不进入循环，n>0，循环内为record
	for(int i=0;i<n;i++){
		sem::Record *temp = (sem::Record*) check;
		name = idd->id_list[i]->idt;// 获取前一个的名字
		left_value->locations.push_back(std::find(temp->names.begin(),temp->names.end(),name)-temp->names.begin());
		check = ca->find_var(name);
	}
	// array类型检测未完成
	if (check->is_const) throw sem::SemException("Var: Const variable "+name+" can't be changed!");
	return;
}


