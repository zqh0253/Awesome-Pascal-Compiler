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
    const int ENUM = 6;
    const int RECORD = 7;
}

class SemType {
public:
	int base_type;
    int is_const;
	std::vector<SemType> advanced_type;
    std::vector<std::string> val_name;
};

/*******************函数信息******************/

class SemanticAnalyzer {
public:
    SemanticAnalyzer(){}
    std::string name;
    std::map<std::string, SemType> vars;
    // std::map<std::string, > consts;
    // std::map<std::string, > labels;
    // std::map<std::string, > funcs;

    ~SemanticAnalyzer(){}
};

#endif