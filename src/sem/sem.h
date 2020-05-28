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

	class Range : SemType {
	public:
		Range() = default;

		int begin, end;

		~Range() = default;
	};

	class Array : SemType {
	public:
		Array() = default;

		int begin, end;
		SemType *el_type;

		~Array() = default;
	};

	class String : SemType {
	public:
		String() = default;
		int size;
		~String() = default;
	};

	class Record : SemType {
	public:
		Record() = default;
		std::string llvm_name;
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

		std::string name;
		std::map<std::string, SemType *> vars;
		// std::map<std::string, > consts;
		// std::map<std::string, > labels;
		std::map<std::string, FuncInfo *> funcs;

		SemanticAnalyzer *last;

		~SemanticAnalyzer() = default;
	};
}
#endif