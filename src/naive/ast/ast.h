#ifndef AST_H_ 
#define AST_H_

#include<string>
#include<vector>
#include<iostream>

class Node;
class Program;
class ProgramHeading;
class Routine;
class ID;
class IDList;
class RoutineHead;
class RoutineBody;
class LabelPart; 
class ConstPart; 
class TypePart; 
class VarPart; 
class RoutinePart;
class ConstExpr;
class ConstExprList;
class ConstValue;
    class Integer;
    class Real;
    class Char;
    class String;
    class SysCon;
class TypeDecList;
class TypeDec;
    class SimpleTypeDec;
        class SysTypeDec;
        //class ID
        //class IDList
        class RangeTypeDec;
    class ArrayTypeDec;
    class RecordTypeDec;
class TypeDef;


class Node {
    public:
        Node(){}
        ~Node() {}

        bool is_leaf, is_root;
        std::string name;

        virtual std::vector<Node *> get_descendants() = 0;
        void prt(int step);
};

class Program : public Node {
    public:
        Program(ProgramHeading* ph, Routine* rt): program_heading(ph), routine(rt) {
            this->is_leaf = false;
            this->name = "Program";
        }
        ~Program(){}

        ProgramHeading * program_heading;
        Routine * routine;

        std::vector<Node *> get_descendants();
};

class ID : public Node {
    public:
        ID (std::string _id) : idt(_id) {
            this->is_leaf = true;
            this->name = "ID";
        }
        ~ID() {}

        std::string idt;

        std::vector<Node *> get_descendants();
};

class IDList : public Node {
    public:
        IDList (){}
        ~IDList (){}

        std::vector<ID *> ID_list;
        void add(ID *);
};

class ProgramHeading : public Node {
    public:
        ProgramHeading(ID * idt) : program_ID(idt) {
            this->is_leaf = false;
            this->name = "ProgramHeading";
        }
        ~ProgramHeading(){}

        ID * program_ID;

        std::vector<Node *> get_descendants();
};

class Routine : public Node {
    public:
        Routine(RoutineHead * rh, RoutineBody * rb): routine_head(rh), routine_body(rb) {
            this->is_leaf = false;
            this->name = "Routine";
        }
        ~Routine() {}

        RoutineHead * routine_head;
        RoutineBody * routine_body;

        std::vector<Node *> get_descendants();
};

class RoutineHead : public Node {
    public:
        RoutineHead(LabelPart * lp, ConstPart * cp, TypePart * tp, VarPart * vp, RoutinePart * rp): 
            label_part(lp), const_part(cp), type_part(tp), var_part(vp), routine_part(rp) {}
        ~RoutineHead() {}

        LabelPart * label_part;
        ConstPart * const_part;
        TypePart * type_part;
        VarPart * var_part;
        RoutinePart * routine_part;
};

class LabelPart : public Node {
    // Empty class
    public:
        LabelPart(){}
        ~LabelPart(){}
};

class ConstPart : public Node {
    public:
        ConstPart(ConstExprList * cel): const_expr_list(cel){}
        ~ConstPart(){}

        ConstExprList* const_expr_list;
};

class ConstExprList : public Node {
    public:
        ConstExprList() {}
        ~ConstExprList() {}

        std::vector<ConstExpr *> const_expr_list;

        void add(ConstExpr * ce);
};

class ConstExpr : public Node {
    // NAME EQUAL const_value SEMI
    public:
        ConstExpr(ConstValue * cv): const_value(cv) {}
        ~ConstExpr() {}

        ConstValue * const_value;
};

class ConstValue : public Node {
    // Integer | Real | Char | String | SYS_CON
    public:
        ConstValue(){}
        ~ConstValue() {}
};

class Integer : public ConstValue {
    public:
        Integer(int _num):integer(_num) {}
        ~Integer() {}

        const int integer;
};

class Real : public ConstValue {
    public:
        Real(float _real):real(_real) {}
        ~Real() {}

        const float real;
};

class Char : public ConstValue {
    public:
        Char(char _chr):chr(_chr) {}
        ~Char() {}

        const char chr;
};

class SysCon : public ConstValue {
    // {0: "maxint", 1: "true", 2: "false"}
    public:
        SysCon(int _type):type(_type) {}
        ~SysCon() {}

        int type;
};

class TypePart : public Node {
    // TYPE TypeDeclList | epsilon
    public:
        TypePart(TypeDecList * tdl): type_dec_list(tdl){}
        ~TypePart(){}

        TypeDecList * type_dec_list;
};

class TypeDecList : public Node {
    public:
        TypeDecList() {}
        ~TypeDecList() {}

        std::vector<TypeDef *> type_definition_list;
        void add(TypeDef * td);
};

class TypeDef : public Node {
    // NAME EQUAL TypeDec SEMI
    public:
        TypeDef(TypeDec * td):type_dec(td) {}
        ~TypeDef() {}

        TypeDec * type_dec;
};

class TypeDec : public Node {
    public:
        TypeDec() {}
        ~TypeDec() {}

};

class VarPart : public Node {

};

class RoutinePart : public Node {

};

class RoutineBody : public Node {

};
#endif

// TODO: ADD virtual function to each class
// TODO: template class