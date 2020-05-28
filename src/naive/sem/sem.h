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
    SemType(){}
    int type; // 表示 BuiltinType 或 Range 或 Array 或 Record
    bool is_const;
    int get_type();
    ~SemType(){}
};

class Range : SemType {
    Range(){}
    int begin, end;
    ~Range(){}
};

class Array : SemType {
    Array(){}
    int begin, end;
    SemType *type;
    ~Array(){}
};

class Record : SemType {
    Record(){}
    std::vector<std::string> names;
    std::vector<SemType*> types;
    ~Record(){}
};

/*******************函数信息******************/
class FuncInfo{
public:
    FuncInfo(){}
    SemType* ret;
    std::vector<SemType*> types;
    std::vector<std::string> names;
    ~FuncInfo(){}
};

class SemanticAnalyzer {
public:
    SemanticAnalyzer(){}
    std::string name;
    std::map<std::string, SemType*> vars;
    // std::map<std::string, > consts;
    // std::map<std::string, > labels;
    std::map<std::string, FuncInfo*> funcs;

    ~SemanticAnalyzer(){}
};

#endif