#ifndef SEM_H_
#define SEM_H_

#include<string>
#include<vector>
#include<iostream>
#include <map>

/*******************变量类型******************/
namespace TypeList {
	const int VOID = -1;
	const int INT = 0;
	const int REAL = 1;
	const int CHAR = 2;
	const int STRING = 3;
	const int BOOL = 4;
	const int ARRAY = 5;
	const int Range = 6;
	const int RECORD = 7;
}

class SemType {
public:
	SemType() = default;
	int type; // 表示 BuiltinType 或 Range 或 Array 或 Record
	bool is_const;
	int get_type() { return type; }
	~SemType() = default;
};

class Range : SemType {
	Range() = default;
	int begin, end;
	~Range() = default;
};

class Array : SemType {
	Array() = default;
	int begin, end;
	SemType *type;
	~Array() = default;
};

class Record : SemType {
	Record() = default;
	std::vector<std::string> names;
	std::vector<SemType*> types;
	~Record() = default;
};

/*******************函数信息******************/
class FuncInfo {
public:
	FuncInfo() = default;
	SemType* ret;
	std::vector<SemType*> types;
	std::vector<std::string> names;
	~FuncInfo() = default;
};

class SemanticAnalyzer {
public:
	SemanticAnalyzer() = default;
	std::string name;
	std::map<std::string, SemType*> vars;
	// std::map<std::string, > consts;
	// std::map<std::string, > labels;
	std::map<std::string, FuncInfo*> funcs;

	~SemanticAnalyzer() = default;
};

#endif