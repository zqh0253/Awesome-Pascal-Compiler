#include "sem.h"
#include "ast/ast.h"
#include "gen/code_generator.h"

/* ------------ Semantic Struct ------------ */
namespace sem {
	const int ERROR = -1;
	const int INT = 0;
	const int REAL = 1;
	const int CHAR = 2;
	const int BOOL = 3;
	const int VOID = 4;
	const int STRING = 5;
	const int RANGE = 6;
	const int ARRAY = 7;
	const int RECORD = 8;

	const int CONST = 6;
	const int PTR = 12;
	std::string RECORD_FIRST_NAME = "$record_";
	std::string STRING_FIRST_NAME = "$string_";
	std::string RANGE_FIRST_NAME = "$range_";
	std::string ARRAY_FIRST_NAME = "$array_";
	SemType *Entity_List[20] = {nullptr};
	std::map<std::string, SemType *> Global_Types;
	std::string TYPES_MAP[9]={"int","real","char","bool","void","string","range","array"};
}

void sem::Init(){
	for(int i=0;i<sem::CONST;i++){
		sem::Entity_List[i] = new SemType(i);
		sem::Entity_List[i+sem::CONST] = new SemType(i,true);
	}
	return;
}

bool sem::CanBeOperated(const int a){
	if (a == sem::INT || a == sem::REAL || a == sem::BOOL || a == sem::CHAR) return true;
	else return false;
}

bool sem::CanAssign(const int a, const int b){
	if (a == b) return true;
	// 目前四个可以乱来，后续有变化的话再修改
	if (CanBeOperated(a) && CanBeOperated(b)) return true;
	// 允许char对于string赋值
	if (a == sem::STRING && b == sem::CHAR) return true;
	return false;
}

int sem::BasicOperate(const int a, const int b){
	// 保证a b 在int real char bool内
	if (sem::CanBeOperated(a) && sem::CanBeOperated(b)){
		// 如果a和b相等，证明是同类型运算，返回对应类型
		if (a == b) return a;
		// a与b不同类型
		else{
			// a b中存在real, 直接返回real
			if (a == sem::REAL || b == sem::REAL) return sem::REAL;
			// a b中不存在real，但是存在int，直接返回int
			else if (a == sem::INT || b == sem::INT) return sem::INT;
			// a b中不存在real和int，但是存在char，直接返回char
			else if (a == sem::CHAR || b == sem::CHAR) return sem::CHAR;
			// a b中不存在real和int和char，直接返回bool————这是逻辑上不可能发生的
			else return sem::BOOL;
		}
	}
	// 如果a或者b有一个不是可运算类型，直接返回-1
	else return sem::ERROR;
}

void sem::SemType::display(int i){
    std::cout << sem::TYPES_MAP[this->type];
	if (this->is_ptr)
        std::cout << " pointer";

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

sem::SemType *sem::SemanticAnalyzer::find_var(const std::string &name){
	sem::SemanticAnalyzer* temp = this;
	for(temp=this; temp != this->global_sem(); temp = temp->last_sem()){
		if(temp->vars.count(name)) return temp->vars[name];
	}
	if(temp->vars.count(name)) return temp->vars[name];
	else throw sem::SemException("Var: variable '" + name + "' has not be defined!");
}

sem::SemType *sem::SemanticAnalyzer::find_type(const std::string &name){
	sem::SemanticAnalyzer* temp = this;
	for(temp=this; temp != this->global_sem(); temp = temp->last_sem()){
		if(temp->types.count(name)) return temp->types[name];
	}
	if(temp->types.count(name)) return temp->types[name];
	else throw sem::SemException("Type: type '" + name + "' has not be defined!");
}

sem::FuncInfo *sem::SemanticAnalyzer::find_func(const std::string &name){
	sem::SemanticAnalyzer* temp = this;
	for(temp=this; temp != this->global_sem(); temp = temp->last_sem()){
		if(temp->funcs.count(name)) return temp->funcs[name];
	}
	if(temp->funcs.count(name)) return temp->funcs[name];
	else throw sem::SemException("Func: function '" + name + "' has not be defined!");
}

bool sem::SemanticAnalyzer::is_available(std::string &name, const std::string &e){
	if (this->vars.count(name) || this->types.count(name) || this->funcs.count(name) || name == "printf"){
		throw sem::SemException(e);
	}
	return true;
}

/* ------------ Semantic Analyze ------------ */
void Node::sem_analyze(sem::SemanticAnalyzer *ca) {
	return; // 部分结点不需要，直接返回即可
}


void ConstExpr::sem_analyze(sem::SemanticAnalyzer *ca) {
	std::string &const_name = id->idt;
	/* 类型检查 */
	if (! ca->is_available(const_name, "Const: the const variavle name '"+const_name+"' has a conflict!")) return;
	/* 维护语义 */
	sem::SemType *const_type = nullptr;
	const_type = sem::Entity_List[const_value->sem_type+sem::CONST];
	ca->vars[const_name] = const_type;
	return;
}

void TypeDef::sem_analyze(sem::SemanticAnalyzer *ca){
	/* 类型检查 */
	if (! ca->is_available(id->idt,("TypeDef: Type name '"+id->idt+"' has a conflict!"))) return;
	/* 维护语义 */
	ca->types[id->idt] = type_dec->sem_type;
	return;
}

void TypeDec::sem_analyze(sem::SemanticAnalyzer *ca){
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
		if (range_type->type == RangeType::IDENTIFY){
			if( ca->find_var(range_type->left_id->idt)->type != sem::INT ||
				ca->find_var(range_type->right_id->idt)->type != sem::INT)
				throw sem::SemException("Type: Range can only be defined by inerger!");
		}
		else if (range_type->type == RangeType::CONST){
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
				throw sem::SemException("Def: Type '" + temp->type_dec->name + "' is not exist!");
		for(int j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			// 检查变量名是否冲突（record内部）
			if (std::find(re->names.begin(),re->names.end(),name) != re->names.end())
				throw sem::SemException("Def: Variable name '" + name + "' in record '" + re_name + "' has a conflict!");
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
			throw sem::SemException("Def: Type '" + temp->type_dec->name + "' is not exist!");
		for(int j=0; j != temp->id_list->ID_list.size();j++){
			std::string name = temp->id_list->ID_list[j]->idt;
			// 检查变量名是否冲突（当前语义块内部）
			if (! ca->is_available(name,("VarDef: Variable name '"+name+"' has a conflict!"))) return;
			else ca->vars[name] = temp->type_dec->sem_type;
		}
	}
	return;
}

void SubProgramHead::sem_analyze(sem::SemanticAnalyzer *ca){
	// 检查命名是否合法
	sem::FuncInfo *temp;
	if (! ca->is_available(id->idt, ("FuncDef: Function name '"+id->idt+"' has a conflict!"))) return;
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
	// local指针记录
	temp->local = ca;
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
					throw sem::SemException("Function: Type '" + temp->simple_type->id->idt + "' is not exist!");
			for(int j=0; j != temp->id_list->ID_list.size();j++){
				std::string name = temp->id_list->ID_list[j]->idt;
				// 检查变量名是否冲突（function内部）
				if (std::find(names.begin(),names.end(),name) != names.end())
					throw sem::SemException("Function: Variable name '" + name + "' in parameters has a conflict!");
				else {
					func_info->types.push_back(make_pair(name,temp->simple_type->sem_type));
				}
				names.push_back(name);
			}
		}
	}
	return;
}

void AssignStmt::sem_analyze(sem::SemanticAnalyzer* ca){
	// 需要判定左右是否一样
	if (type==AssignStmt::SINGLE){
		// 判定是否为常量
		if (idd->re_mem->real_type->is_const) throw sem::SemException("Var: Const variable '"+idd->re_mem->name+"' can't be changed!");
		// 只判定数字，所以对于结构体、数组可能存在问题
		if (! sem::CanAssign(idd->re_mem->real_type->type, e1->resault_type))
			// 对于不可赋值情况，直接抛出错误
			throw sem::SemException("Assign : '=' can't be used between '"+sem::TYPES_MAP[idd->re_mem->real_type->type]+"' and '"+sem::TYPES_MAP[e1->resault_type]+"'!");
	}
	else if (type==AssignStmt::ARRAY) {
		// 首先判定表达式1作为下标是否为整数
		if (e1->resault_type != sem::INT) throw sem::SemException("Expression : the index of array '"+idd->re_mem->name+"' must be an integer!");
		sem::Array *temp = (sem::Array*)idd->re_mem->real_type;
		// 判定是否为常量
		if (temp->el_type->is_const) throw sem::SemException("Var: Const variable '"+idd->re_mem->name+"' can't be changed!");
		// 判断赋值是否允许
		if (! sem::CanAssign(temp->el_type->type, e1->resault_type))
			throw sem::SemException("Assign : '=' can't be used between '"+sem::TYPES_MAP[temp->el_type->type]+"' and '"+sem::TYPES_MAP[e1->resault_type]+"'!");
	}
	else throw sem::SemException("Unknown error : in AssignStmt");
	return;
}

void IDDotted::sem_analyze(sem::SemanticAnalyzer *ca){
	std::string name = id_list[0]->idt;
	// 建立成员变量结构
	sem::SemType *real_type = ca->find_var(name);
	re_mem = new sem::RecordMember(name,real_type);
	// 当n=0，不进入循环，n>0，循环内为record
	for(int i=1;i<id_list.size();i++){
		sem::Record *temp = (sem::Record*) real_type;
		name = id_list[i]->idt;// 获取前一个的名字
		auto loc=std::find(temp->names.begin(),temp->names.end(),name);
		// 判断record中变量是否存在
		if(loc != temp->names.end()){
			re_mem->locations.push_back(loc-temp->names.begin());
			real_type = temp->types[name];
		}
		else throw sem::SemException("Var: Variable name '" + name + "' can't be found in record '" + temp->type_name + "'!");
	}
	re_mem->real_type = real_type;
	return;
}

/** Expression **/
// 表达式相关目前只需要做类型检查和隐式转换
void Expression::sem_analyze(sem::SemanticAnalyzer *ca){
	if (op == Expression::SINGLE) resault_type = expr->resault_type;
	else {
		if (sem::BasicOperate(expr->resault_type, expression->resault_type) == sem::ERROR) 
			throw sem::SemException("Expression : '"+sem::TYPES_MAP[expr->resault_type]+"' and '"+sem::TYPES_MAP[expression->resault_type]+"' can't be operated!");
		// 其他所有运算都是布尔运算
		resault_type = sem::BOOL;
	}
	return;
}

void Expr::sem_analyze(sem::SemanticAnalyzer *ca){
	if (op == Expr::SINGLE) resault_type = term->resault_type;
	else {
		resault_type = sem::BasicOperate(term->resault_type, expr->resault_type);
		if (resault_type == sem::ERROR) 
			throw sem::SemException("Expression : '"+sem::TYPES_MAP[term->resault_type]+"' and '"+sem::TYPES_MAP[expr->resault_type]+"' can't be operated!");
	}
	return;
}

void Term::sem_analyze(sem::SemanticAnalyzer *ca){
	if (op == Term::SINGLE)
		resault_type = factor->resault_type;
	else {
		// 模运算需要保证左右都是整型
		if (op == Term::MOD && (factor->resault_type == sem::REAL || term->resault_type == sem::REAL))
			throw sem::SemException("Expression : '%' can't be used for real number!");
		else resault_type = sem::BasicOperate(factor->resault_type, term->resault_type);
		if (resault_type == sem::ERROR) 
			throw sem::SemException("Expression : '"+sem::TYPES_MAP[factor->resault_type]+"' and '"+sem::TYPES_MAP[term->resault_type]+"' can't be operated!");
	}
	return;
}

void Factor::sem_analyze(sem::SemanticAnalyzer *ca){
	if (type == Factor::FUNC_WITH_NO_ARGS || type == Factor::FUNC){
		sem::FuncInfo *temp = (sem::FuncInfo*) ca->find_func(id1->idt);
		resault_type = temp->ret->type;
		if (id1->idt == "printf") return;
		// 函数参数检查
		if (type == Factor::FUNC){
			if (args_list->args_list.size() != temp->types.size()-1) throw sem::SemException("Parameters : the function '"+temp->types[temp->types.size()-1].first+"' needs "+ std::to_string(temp->types.size()-1)+" parameters!");
			for(int i=0;i<temp->types.size()-1;i++){
				// 对于record和array检测可能存在一些问题
				if (args_list->args_list[i]->resault_type != temp->types[i].second->type)
					throw sem::SemException("Parameter : the type of parametr '"+temp->types[i].first+"' is not '"+sem::TYPES_MAP[args_list->args_list[i]->resault_type]+"'!");
			}
		}
		// 判断函数是否不需要参数，types内部存在函数本身所以判定>1代表需要参数
		else if (temp->types.size()>1) throw sem::SemException("Parameters : the function '"+temp->types[temp->types.size()-1].first+"' needs "+ std::to_string(temp->types.size()-1)+" parameters!");
	}
	else if (type == Factor::CONST_VALUE)
		resault_type = const_value->sem_type;
	else if (type == Factor::EXPRESSION)
		resault_type = expr->resault_type;
	else if (type == Factor::NOT_FACTOR || type == Factor::MINUS_FACTOR){
		// 非运算    取负号运算
		resault_type = factor->resault_type;
		// 检测运算是否可行
		if (!sem::CanBeOperated(resault_type)) throw sem::SemException("Expression : 'minus' can't be used for '"+sem::TYPES_MAP[resault_type]+"'!");
	}
	else if (type == Factor::MEMBER)
		resault_type = idd->re_mem->real_type->type;
	else if (type == Factor::ARRAY){
		sem::Array *temp = (sem::Array*)idd->re_mem->real_type;
		resault_type = temp->el_type->type;
	}
	else throw sem::SemException("Unknown error : in factor !");
	return;
}

/****/

void ProcStmt::sem_analyze(sem::SemanticAnalyzer *ca){
	if (id->idt == "printf") return;
	sem::FuncInfo *temp = (sem::FuncInfo*) ca->find_func(id->idt);
	if (type == ProcStmt::SINGLE_ID){
		// 判断函数是否不需要参数，types内部存在函数本身所以判定>1代表需要参数
		if(temp->types.size() > 1) throw sem::SemException("Parameters : the function '"+temp->types[temp->types.size()-1].first+"' needs "+ std::to_string(temp->types.size()-1)+" parameters!");
	}
	else if (type == ProcStmt::ID_WITH_ARGS){
		if (args_list->args_list.size() != temp->types.size()-1) throw sem::SemException("Parameters : the function '"+temp->types[temp->types.size()-1].first+"' needs "+ std::to_string(temp->types.size()-1)+" parameters!");
		for(int i=0;i<temp->types.size()-1;i++){
			// 对于一般类型判定
			if (args_list->args_list[i]->resault_type != temp->types[i].second->type)
				throw sem::SemException("Parameter : the type of parametr '"+temp->types[i].first+"' is not '"+sem::TYPES_MAP[args_list->args_list[i]->resault_type]+"'!");
			// 对于record和array追加判定
			if (args_list->args_list[i]->resault_type == sem::RECORD){

			}
		}
	}
	return;
}
