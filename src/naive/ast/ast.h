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
class ConstExpr;
class ConstExprList;
class ConstValue;
class TypeDecList;
class TypeDec;
class TypeDef;
class SysType;
class RangeType;
class ArrayType;
class RecordType;
class SimpleType;
class VarDecList;
class VarDec;

class RoutinePart;
class SubProgram;
class Parameters;
class ParaDecList;
class ParaTypeList;

class Statement;
class AssignStmt;
class ProcStmt;
class CompoundStmt;
class IfStmt;
class RepeatStmt;
class WhileStmt;
class ForStmt;
class CaseStmt;
class GotoStmt;
class Expression;

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
        IDList (){
            this->is_leaf = false;
            this->name = "IDList";
        }
        ~IDList (){}

        std::vector<ID *> ID_list;
        void add(ID *);
        std::vector<Node *> get_descendants();
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
            label_part(lp), const_part(cp), type_part(tp), var_part(vp), routine_part(rp) {
            this->is_leaf = false;
            this->name = "RoutineHead";
        }
        ~RoutineHead() {}

        LabelPart * label_part;
        ConstPart * const_part;
        TypePart * type_part;
        VarPart * var_part;
        RoutinePart * routine_part;

        std::vector<Node *> get_descendants();
};

class LabelPart : public Node {
    // Empty class
    public:
        LabelPart(){
            this->is_leaf = true;
            this->name = "LabelPart";
        }
        ~LabelPart(){}

        std::vector<Node *> get_descendants();
};

class ConstPart : public Node {
    public:
        ConstPart():is_empty(true) {
            this->is_leaf = true;
            this->name = "ConstPart";
        }
        ConstPart(ConstExprList * cel): const_expr_list(cel), is_empty(false){
            this->is_leaf = false;
            this->name = "ConstPart";
        }
        ~ConstPart(){}

        ConstExprList* const_expr_list;
        bool is_empty;
        std::vector<Node *> get_descendants();
};

class ConstExprList : public Node {
    public:
        ConstExprList() {
            this->is_leaf = false;
            this->name = "ConstExprList";
        }
        ~ConstExprList() {}

        std::vector<ConstExpr *> const_expr_list;

        void add(ConstExpr * ce);
        std::vector<Node *> get_descendants();
};

class ConstExpr : public Node {
    // NAME EQUAL const_value SEMI
    public:
        ConstExpr(ID * _id, ConstValue * cv): id(_id), const_value(cv) {
            this->is_leaf = false;
            this->name = "ConstExpr";
        }
        ~ConstExpr() {}

        ID * id;
        ConstValue * const_value;
        std::vector<Node *> get_descendants();
};

class ConstValue : public Node {
    // Integer | Real | Char | String | SYS_CON
    public:
        enum {INTEGER, REAL, CHAR, STRING, SYSCON} type;
        enum SYSCON {FALSE, TRUE, MAXINT} sys_con;
        ConstValue(int i){
            this->type = INTEGER;
            this->integer = i;
            this->is_leaf = true;
            this->name = "ConstValue";
        }
        ConstValue(float f){
            this->type = REAL;
            this->real = f;
            this->is_leaf = true;
            this->name = "ConstValue";
        }
        ConstValue(char c){
            this->type = CHAR;
            this->ch = c;
            this->is_leaf = true;
            this->name = "ConstValue";
        }
        ConstValue(std::string s){
            this->type = STRING;
            this->str = s;
            this->is_leaf = true;
            this->name = "ConstValue";
        }
        ConstValue(enum SYSCON sc){
            this->type = SYSCON;
            this->sys_con = sc;
            this->is_leaf = true;
            this->name = "ConstValue";
        }
        ~ConstValue() {}

        int integer;
        float real;
        char ch;
        std::string str;
        
        std::vector<Node *> get_descendants();
};

class TypePart : public Node {
    // TYPE TypeDeclList | epsilon
    public:
        TypePart():is_empty(true) {
            this->is_leaf = true;
            this->name = "TypePart";
        }
        TypePart(TypeDecList * tdl): type_dec_list(tdl), is_empty(false){
            this->is_leaf = false;
            this->name = "TyepPart";
        }
        ~TypePart(){}

        TypeDecList * type_dec_list;
        bool is_empty;
        std::vector<Node *> get_descendants();
};

class TypeDecList : public Node {
    public:
        TypeDecList() {
            this->is_leaf = false;
            this->name = "TypeDecList";
        }
        ~TypeDecList() {}

        std::vector<TypeDef *> type_definition_list;
        void add(TypeDef * td);
        std::vector<Node *> get_descendants();
};

class TypeDef : public Node {
    // NAME EQUAL TypeDec SEMI
    public:
        TypeDef(ID * _id, TypeDec * td):id(_id), type_dec(td) {
            this->is_leaf = false;
            this->name = "TypeDef";
        }
        ~TypeDef() {}

        ID * id;
        TypeDec * type_dec;
        std::vector<Node *> get_descendants();
};

class TypeDec : public Node {
    public:
        enum type {SIMPLE, ARRAY, RECORD} type;
        TypeDec(SimpleType * st):simple_type(st) {
            this->type = SIMPLE;
            this->is_leaf = false;
            this->name = "TypeDec";
        }
        TypeDec(ArrayType * at):array_type(at) {
            this->type = ARRAY;
            this->is_leaf = false;
            this->name = "TypeDec";
        }
        TypeDec(RecordType * rt):record_type(rt) {
            this->type = RECORD;
            this->is_leaf = false;
            this->name = "TypeDec";
        }
        ~TypeDec() {}

        SimpleType * simple_type;
        ArrayType * array_type;
        RecordType * record_type;
        std::vector<Node *> get_descendants();
};

class SimpleType : public Node {
    public:
        enum type {SYS_TYPE, IDENTIFY, IDLIST, RANGE, STRING} type;
        SimpleType(SysType * st):sys_type(st) {
            this->type = SYS_TYPE;
            this->is_leaf = false;
            this->name = "SimpleType";
        }
        SimpleType(ID * _id):id(_id) {
            this->type = IDENTIFY;
            this->is_leaf = false;
            this->name = "SimpleType";
        }
        SimpleType(IDList * il):id_list(il) {
            this->type = IDLIST;
            this->is_leaf = false;
            this->name = "SimpleType";
        }
        SimpleType(RangeType * rt):range_type(rt) {
            this->type = RANGE;
            this->is_leaf = false;
            this->name = "SimpleType";
        }
        ~SimpleType() {}

        SysType * sys_type;
        ID * id;
        IDList * id_list;
        RangeType * range_type;
        std::vector<Node *> get_descendants();
};

class SysType : public Node {
    public:
        enum t {BOOLEAN, CHAR, INTEGER, REAL, STRING} type;
        SysType(enum t type) {
            this->type = type;
            this->is_leaf = true;
            this->name = "SysType";
        }
        ~SysType() {}

        std::vector<Node *> get_descendants();
};

class RangeType : public Node {
    public:
        enum type {IDENTIFY, CONST} type;
        RangeType(ID * id1, ID * id2): left_id(id1), right_id(id2) {
            this->type = IDENTIFY;
            this->is_leaf = false;
            this->name = "RangeType";
        }
        RangeType(ConstValue * lc, ConstValue * rc, bool lm, bool rm): left_const(lc), right_const(rc), left_minus(lm), right_minus(rm) {
            this->type = CONST;
            this->is_leaf = false;
            this->name = "RangeType";
        }
        ~RangeType() {}

        ID * left_id, * right_id;
        ConstValue * left_const, * right_const;
        bool left_minus, right_minus;
        std::vector<Node *> get_descendants();
};

class ArrayType : public Node {
    // ARRAY (SimpleType) OF TypeDec
    public:
        ArrayType(SimpleType * st, TypeDec * td): simple_type(st), type_dec(td) {
            this->is_leaf = false;
            this->name = "ArrayType";
        }
        ~ArrayType() {}

        SimpleType * simple_type;
        TypeDec * type_dec; 
        std::vector<Node *> get_descendants();
};

class RecordType : public Node {
    // RECORD VarDecList END
    public:
        RecordType(VarDecList * vdl):record_dec_list(vdl){
            this->is_leaf = false;
            this->name = "RecordType";
        }
        ~RecordType() {}

        VarDecList * record_dec_list;
        std::vector<Node *> get_descendants();
};

class VarPart : public Node {
    public:
        VarPart():is_empty(true) {
            this->is_leaf = true;
            this->name = "VarPart";
        }
        VarPart(VarDecList * vdl):var_dec_list(vdl), is_empty(false) {
            this->is_leaf = false;
            this->name = "VarPart";
        }
        ~VarPart() {}

        bool is_empty;
        VarDecList * var_dec_list;
        std::vector<Node *> get_descendants();
};

class VarDecList : public Node {
    public:
        VarDecList(){
            this->is_leaf = false;
            this->name = "VarDecList";
        }
        ~VarDecList(){}

        std::vector<VarDec *> var_dec_list;
        void add(VarDec *);
        std::vector<Node *> get_descendants();
};

class VarDec : public Node {
    // IDList COLON TypeDec SEMI
    public:
        VarDec(IDList * il, TypeDec * td): id_list(il), type_dec(td) {
            this->is_leaf = false;
            this->name = "VarDec";
        }    
        ~VarDec() {}

        IDList * id_list;
        TypeDec * type_dec;
        std::vector<Node *> get_descendants();
};

class RoutinePart : public Node {
    public:
        RoutinePart(){
            this->is_leaf = false;
            this->name = "RoutinePart";
        }
        ~RoutinePart() {}

        std::vector<SubProgram *> func_and_proc;
        void add(SubProgram *);
        std::vector<Node *> get_descendants();
};

class SubProgram : public Node {
    public:
        enum t {FUNCTION, PROCEDURE} type;
        SubProgram (ID * _id, Parameters * p, SimpleType * st, Routine * rt): id(_id), parameters(p), simple_type(st), routine(rt) {
            this->is_leaf = false;
            this->name = "Subprogram";
            this->type = FUNCTION;
        }
        SubProgram (ID * _id, Parameters * p, Routine * rt): id(_id), parameters(p), routine(rt) {
            this->is_leaf = false;
            this->name = "Subprogram";
            this->type = PROCEDURE;
        }
        ~SubProgram () {}

        ID * id;
        Parameters * parameters;
        SimpleType * simple_type;
        Routine* routine;
        std::vector<Node *> get_descendants();
};

class Parameters : public Node {
    public:
        Parameters () {
            this->is_leaf = true;
            this->name = "Parameters";
        }
        Parameters (ParaDecList * pdl) : para_dec_list(pdl) {
            this->is_leaf = false;
            this->name = "Parameters";
        }
        ~Parameters () {}

        ParaDecList * para_dec_list;
        std::vector<Node *> get_descendants();
};

class ParaDecList : public Node {
    public:
        ParaDecList () {
            this->is_leaf = false;
            this->name = "ParaDecList";
        }
        ~ParaDecList () {}

        std::vector<ParaTypeList *> para_dec_list;
        void add(ParaTypeList *);
        std::vector<Node *> get_descendants();
};

class ParaTypeList : public Node {
    public:
        ParaTypeList(IDList * il, SimpleType * st):id_list(il), simple_type(st){
            this->is_leaf = false;
            this->name = "ParaTypeList";
        }
        ~ParaTypeList() {}

        IDList * id_list;
        SimpleType * simple_type;
        std::vector<Node *> get_descendants();
};


class RoutineBody : public Node {
    public:
        RoutineBody(){
            this->is_leaf = false;
            this->name = "RoutineBody";
        }
        ~RoutineBody() {}

        std::vector<Statement *> statement_list;
        void add(Statement *);
        std::vector<Node *> get_descendants();
};

class Statement : public Node {
    public:
        enum {ASSIGN, PROC, COMPOUND, IF, REPEAT, WHILE, FOR, CASE, GOTO} type;
        Statement (AssignStmt * as) : assign_stmt(as){
            this->is_leaf = true;
            this->type = ASSIGN;
            this->name = "Statement";
        }
        Statement (ProcStmt * ps) : proc_stmt(ps){
            this->is_leaf = true;
            this->type = PROC;
            this->name = "Statement";
        }
        Statement (CompoundStmt * cs) : compound_stmt(cs){
            this->is_leaf = true;
            this->type = COMPOUND;
            this->name = "Statement";
        }
        Statement (IfStmt * is) : if_stmt(is){
            this->is_leaf = true;
            this->type = IF;
            this->name = "Statement";
        }
        Statement (RepeatStmt * rs) : repeat_stmt(rs){
            this->is_leaf = true;
            this->type = REPEAT;
            this->name = "Statement";
        }
        Statement (WhileStmt * ws) : while_stmt(ws){
            this->is_leaf = true;
            this->type = WHILE;
            this->name = "Statement";
        }
        Statement (ForStmt * fs) : for_stmt(fs){
            this->is_leaf = true;
            this->type = FOR;
            this->name = "Statement";
        }
        Statement (CaseStmt * cs) : case_stmt(cs){
            this->is_leaf = true;
            this->type = CASE;
            this->name = "Statement";
        }
        Statement (GotoStmt * gs) : goto_stmt(gs){
            this->is_leaf = true;
            this->type = GOTO;
            this->name = "Statement";
        }
        int anchor = -1;
        AssignStmt * assign_stmt;
        ProcStmt * proc_stmt;
        CompoundStmt * compound_stmt;
        IfStmt * if_stmt;
        RepeatStmt * repeat_stmt;
        WhileStmt * while_stmt;
        ForStmt * for_stmt;
        CaseStmt * case_stmt;
        GotoStmt * goto_stmt;

        void set_anchor(int a);
        std::vector<Node *> get_descendants();
};

class AssignStmt : public Node {
    public:
        // single : a := 1;
        // array  : a[1] := 1;
        // member : a.score := 1; 
        enum {SINGLE, ARRAY, MEMBER} type;
        
};

class Expression : public Node {

};

#endif

// TODO: ADD virtual function, name to each class
// TODO: template class