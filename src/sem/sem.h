#ifndef SEM_H_
#define SEM_H_

#include <string>
#include <vector>
#include <iostream>
#include <map>

/*******************变量类型******************/
namespace sem {
	const int VOID = -1;
	const int INT = 0;
	const int REAL = 1;
	const int CHAR = 2;
	const int STRING = 3;
	const int BOOL = 4;
	const int ARRAY = 5;
	const int RANGE = 6;
	const int RECORD = 7;


	class SemType {
	public:
		SemType(int type) {
			this->type = type;
			this->is_const = false;
		}

		SemType(int type, int is_const) {
			this->type = type;
			this->is_const = is_const;
		}

		int type; // 表示 BuiltinType 或 Range 或 Array 或 Record
		bool is_const;

		~SemType() = default;
	};

	extern SemType *IntTy;
	extern SemType *VoidTy;
	extern SemType *RealTy;
	extern SemType *BoolTy;
	extern SemType *CharTy;
	extern SemType *ConstIntTy;
	extern SemType *ConstVoidTy;
	extern SemType *ConstRealTy;
	extern SemType *ConstBoolTy;
	extern SemType *ConstCharTy;

	class Range : SemType {
	public:
		int begin, end;
		~Range() = default;
	};

	class Array : SemType {
	public:
		int begin, end;
		SemType *el_type;

		~Array() = default;
	};

	class String : SemType {
	public:
		int size;
		~String() = default;
	};

	class Record : SemType {
	public:
		std::string type_name;
		std::map<std::string, std::pair<SemType*, int>> types;
		~Record() = default;
	};

/*******************函数信息******************/
	class FuncInfo {
	public:
		FuncInfo() = default;

		SemType *ret;
		std::vector<SemType *> types;
		std::vector<std::string> names;

		~FuncInfo() = default;
	};

	class SemanticAnalyzer {
	public:
		SemanticAnalyzer() = default;
		SemanticAnalyzer(std::string &name) {
			this->name = name;
		}
		std::string name;
		std::map<std::string, SemType *> vars;
		// std::map<std::string, > consts;
		// std::map<std::string, > labels;
		std::map<std::string, SemType*> types;
		std::map<std::string, FuncInfo *> funcs;
		SemanticAnalyzer *last;

		~SemanticAnalyzer() = default;
	};
}
#endif