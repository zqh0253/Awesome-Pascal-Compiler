#ifndef SEM_H_
#define SEM_H_

#include <string>
#include <vector>
#include <iostream>
#include <map>

class CodeGenerator;
/*******************变量类型******************/
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

	/*
	* 用于区分实际实体
	* 0-5 为基本类型
	* 6-11 为基本类型的常量形式
	*/
	const int CONST = 6;
	extern std::string RECORD_FIRST_NAME;
	extern std::string STRING_FIRST_NAME;
	extern std::string RANGE_FIRST_NAME;
	extern std::string ARRAY_FIRST_NAME;

	class SemanticAnalyzer;
	class SemType {
	public:
		SemType(int _type):type(_type),is_const(false){}
		SemType(int _type, int _is_const):type(_type),is_const(_is_const){}

		int type; // 表示 BuiltinType 或 Range 或 Array 或 Record
		bool is_const;

        virtual void display(int i);
		virtual ~SemType() = default;
		virtual bool operator==(SemType &t){
			return (type== t.type && is_const == t.is_const);
		}
		// virtual ~SemType(){std::cout << "Type is over" << std::endl;}
	};
	// 全局变量
	extern SemType *Entity_List[20];
	extern std::map<std::string, SemType *> Global_Types;
	// 用于处理Clobal_Types的函数
	// bool register_in(std::string name, sem::SemType *ret);

	class Range : public SemType {
	public:
		Range(int _begin, int _end):SemType(RANGE),begin(_begin),end(_end){}
        Range(int _begin, int _end, int _is_const):SemType(RANGE, _is_const),begin(_begin),end(_end){}

		int begin, end;

		~Range() = default;
        // ~Range(){std::cout << "Range is over" << std::endl;}
	};

	class Array : public SemType {
	public:
		Array(int _begin, int _end, SemType *_el_type):SemType(ARRAY),begin(_begin),end(_end),el_type(_el_type){}
        Array(int _begin, int _end, SemType *_el_type, int _is_const):SemType(ARRAY, _is_const),begin(_begin),end(_end),el_type(_el_type){}

		int begin, end;
		SemType *el_type;

		~Array() = default;
        // ~Array(){std::cout << "Array is over" << std::endl;}
	};

	class String : public SemType {
	public:
		String(int _size):SemType(STRING),size(_size){}
		String(int _size, int _is_const):SemType(STRING,_is_const),size(_size){}
		int size;
		~String() = default;
        // ~String(){std::cout << "String is over" << std::endl;}
	};

	class Record : public SemType {
	public:
		Record(std::string name, SemanticAnalyzer *ca):SemType(sem::RECORD),type_name(name),local(ca){}
		std::string type_name;
		SemanticAnalyzer *local;
		std::vector<std::string> names;
		std::map<std::string, SemType*> types;
		void display(int i);
		~Record() = default;
		std::string global_name();
	};

/*******************函数信息******************/
	class FuncInfo {
	public:
		FuncInfo() = default;

		SemType *ret;
		std::vector<std::pair<std::string, SemType*>> types;

		// void display();
		~FuncInfo() = default;
	};

/*******************符号表******************/
	class SemanticAnalyzer {
	public:
		int num=0;
		SemanticAnalyzer(const std::string &name) {
			this->name = name;
		}
		SemanticAnalyzer(const std::string &_name, std::vector<std::pair<std::string, SemType*>> &types):name(_name){
			for(int i=0;i!=types.size();i++){
				this->vars[types[i].first] = types[i].second;
			}
		}
		unsigned int level;
		CodeGenerator *cg;
		std::string name;
		std::map<std::string, SemType *> vars;
		// std::map<std::string, > consts;
		// std::map<std::string, > labels;
		std::map<std::string, SemType*> types;
		std::map<std::string, FuncInfo *> funcs;

		std::string global_name(std::string &local_name) {
			return this->name + "_" + local_name;
		}

		Record *last_record(){
			return (Record*)types[RECORD_FIRST_NAME+std::to_string(num-1)];
		}

		SemanticAnalyzer *last_sem();
		SemanticAnalyzer *global_sem();

		void display(int i);
		// 搜索变量
		SemType *find_var(std::string &name);
		SemType *find_type(std::string &name);

		// 检测本层内冲突
		bool is_availabel(std::string &name, std::string e);

		// ~SemanticAnalyzer() = default;
		~SemanticAnalyzer(){this->display(0);}
	};

	class SemEXception{
	public:
		SemEXception(std::string str):sem_e(str){}
		virtual std::string what(){
			return sem_e;
		}
	private:
		std::string sem_e;
	};

	// 初始化函数
	void Init();
}
#endif