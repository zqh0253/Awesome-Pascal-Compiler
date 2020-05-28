#ifndef AST_H_ 
#define AST_H_

#include<string>
#include<vector>
#include<iostream>
#include "sem/sem.h"

class Node;
class Program;
class ProgramHeading;
class Routine;
class ID;
class IDDotted; // For example, a.teacher.house.block.name. This feature is not supported by the document provided by the instructor.
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
class StatementList;
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
class Expr;
class Term;
class ArgsList;
class ExprList;
class SysProc;
class Factor;
class ElseClause;
class CaseExprList;
class CaseExpr;

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
        RoutineBody(CompoundStmt * cs): compound_stmt(cs){
            this->is_leaf = false;
            this->name = "RoutineBody";
        }
        ~RoutineBody() {}

        CompoundStmt * compound_stmt;
        std::vector<Node *> get_descendants();
};

class CompoundStmt : public Node {
    public:
        CompoundStmt(StatementList * sl):stmt_list(sl){
            this->is_leaf = false;
            this->name = "Compound statement";
        }

        StatementList * stmt_list;
        std::vector<Node *> get_descendants();
};

class StatementList : public Node {
    public:
        StatementList () {
            this->is_leaf = false;
            this->name = "Statement List";
        }

        std::vector<Statement *> stmt_list;
        void add(Statement *);

        std::vector<Node *> get_descendants();
};

class Statement : public Node {
    public:
        enum {ASSIGN, PROC, COMPOUND, IF, REPEAT, WHILE, FOR, CASE, GOTO} type;
        Statement (AssignStmt * as) : assign_stmt(as){
            this->is_leaf = false;
            this->type = ASSIGN;
            this->name = "Statement";
        }
        Statement (ProcStmt * ps) : proc_stmt(ps){
            this->is_leaf = false;
            this->type = PROC;
            this->name = "Statement";
        }
        Statement (CompoundStmt * cs) : compound_stmt(cs){
            this->is_leaf = false;
            this->type = COMPOUND;
            this->name = "Statement";
        }
        Statement (IfStmt * is) : if_stmt(is){
            this->is_leaf = false;
            this->type = IF;
            this->name = "Statement";
        }
        Statement (RepeatStmt * rs) : repeat_stmt(rs){
            this->is_leaf = false;
            this->type = REPEAT;
            this->name = "Statement";
        }
        Statement (WhileStmt * ws) : while_stmt(ws){
            this->is_leaf = false;
            this->type = WHILE;
            this->name = "Statement";
        }
        Statement (ForStmt * fs) : for_stmt(fs){
            this->is_leaf = false;
            this->type = FOR;
            this->name = "Statement";
        }
        Statement (CaseStmt * cs) : case_stmt(cs){
            this->is_leaf = false;
            this->type = CASE;
            this->name = "Statement";
        }
        Statement (GotoStmt * gs) : goto_stmt(gs){
            this->is_leaf = false;
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

class CaseStmt : public Node {
    public:
        CaseStmt(Expression * e, CaseExprList * c):expr(e), case_expr_list(c){
            this->is_leaf = false;
            this->name = "Case Statement";
        }
        ~CaseStmt() {}
        Expression * expr;
        CaseExprList * case_expr_list;
        std::vector<Node *> get_descendants();
};

class CaseExprList : public Node {
    public:
        CaseExprList () {
            this->is_leaf = false;
            this->name = "CaseExprList";
        }
        ~CaseExprList () {}

        std::vector<CaseExpr *> case_expr_list;
        void add(CaseExpr *);
        std::vector<Node *> get_descendants();
};

class CaseExpr : public Node {
    public:
        enum o {CONST, IDENTIFY} type;
        CaseExpr (ConstValue * cv, Statement * s): const_value(cv), stmt(s){
            this->is_leaf = false;
            this->name = "CaseExpr";
            this->type = CONST;
        }
        CaseExpr (IDDotted * _id, Statement * s):idd(_id), stmt(s){
            this->is_leaf = false;
            this->name = "CaseExpr";
            this->type = IDENTIFY;
        }
        ConstValue * const_value;
        IDDotted * idd;
        Statement * stmt;
        std::vector<Node *> get_descendants();
};

class GotoStmt : public Node {
    public:
        GotoStmt(int i):destination(i) {
            this->is_leaf = true;
            this->name = "Goto Statement";
        }

        int destination;
        std::vector<Node *> get_descendants();
};

class AssignStmt : public Node {
    public:
        // single : a := 1; OR a.member := 1;
        // array  : a[1] := 1; 
        enum {SINGLE, ARRAY} type;
        AssignStmt (IDDotted * i, Expression * e): idd(i), e1(e){
            this->is_leaf = false;
            this->name = "Assign Statement";
            this->type = SINGLE;
        }
        AssignStmt (IDDotted * i, Expression * _e1, Expression * _e2) : idd(i), e1(_e1), e2(_e2){
            this->is_leaf = false;
            this->name = "Assign Statement";
            this->type = ARRAY;
        } 
        ~AssignStmt () {}
        IDDotted * idd;
        Expression * e1,* e2;

        std::vector<Node *> get_descendants();
};

class ProcStmt : public Node {
    public:
        enum { SINGLE_ID,               // ID
                ID_WITH_ARGS,           // ID LP args_list RP
                SYS_PROC,               // SYS_PROC
                SYS_PROC_WITH_EXPR,     // SYS_PROC LP expr_list RP
                READ_FACTOR             // If the sys_proc is read
             } type;
        ProcStmt(ID * _id): id(_id) {
            this->is_leaf = false;
            this->name = "Proc Statement";
            this->type = SINGLE_ID;
        }
        ProcStmt(ID * _id, ArgsList * al): id(_id), args_list(al) {
            this->is_leaf = false;
            this->name = "Proc Statement";
            this->type = ID_WITH_ARGS;
        }
        ProcStmt(SysProc * sp): sys_proc(sp) {
            this->is_leaf = false;
            this->name = "Proc Statement";
            this->type = SYS_PROC;
        }
        ProcStmt(SysProc * sp, ExprList * el): sys_proc(sp), expr_list(el) {
            this->is_leaf = false;
            this->name = "Proc Statement";
            this->type = SYS_PROC_WITH_EXPR;
        }
        ProcStmt(SysProc * sp, Factor * f): sys_proc(sp), factor(f) {

        //SHOULD check the sysproc is READ only!
            this->is_leaf = false;
            this->name = "Proc Statement";
            this->type = READ_FACTOR;
        }
        ~ProcStmt() {}

        ID * id;
        ArgsList * args_list;
        SysProc * sys_proc;
        ExprList * expr_list;
        Factor * factor;
        std::vector<Node *> get_descendants();
};

class IfStmt : public Node {
    public:
        IfStmt (Expression * e, Statement * s, ElseClause * ec): expr(e), stmt(s), else_clause(ec) {
            this->is_leaf = false;
            this->name = "If statement";
        }

        Expression * expr;
        Statement * stmt;
        ElseClause * else_clause;
        std::vector<Node *> get_descendants();
};

class ElseClause : public Node {
    public:
        ElseClause () {
            this->is_leaf = true;
            this->name = "Else Clause";
        }
        ElseClause (Statement * s):stmt(s) {
            this->is_leaf = false;
            this->name = "Else Clause";
        }

        Statement * stmt;
        std::vector<Node *> get_descendants();
};

class RepeatStmt : public Node {
    public:
        RepeatStmt (StatementList * sl, Expression * e) : stmt_list(sl), expr(e) {
            this->is_leaf = false;
            this->name = "Repeat Statement";
        }

        StatementList * stmt_list;
        Expression * expr;

        std::vector<Node *> get_descendants();
};

class WhileStmt : public Node {
    public:
        WhileStmt (Expression * e, Statement * s) : expr(e), stmt(s) {
            this->is_leaf = false;
            this->name = "While Statement";
        }
        Expression * expr;
        Statement * stmt;

        std::vector<Node *> get_descendants();
};

class ForStmt : public Node {
    public:
        enum d {TO, DOWNTO} direction;
        ForStmt (IDDotted * i, Expression * e1, Expression * e2, Statement * s, enum d di): idd(i), expr1(e1), expr2(e2), direction(di), stmt(s) {
            this->is_leaf = false;
            this->name = "For Statement";
        }

        IDDotted * idd;
        Expression * expr1, * expr2;
        Statement * stmt;

        std::vector<Node *> get_descendants();
};

class SysProc : public Node {
    public:
        enum t {WRITE, WRITELN, READ} type;
        SysProc (enum t ty): type(ty) {
            this->is_leaf = true;
            this->name = "SysProc";
        }
        ~SysProc() {}

        std::vector<Node *> get_descendants();
};

class IDDotted : public Node {
    public:
        IDDotted() {
            this->is_leaf = false;
            this->name = "ID_dotted";
        }

        std::vector<ID *> id_list;
        void add(ID *);
        std::vector<Node *> get_descendants();
};

class Expression : public Node {
    public:
        enum o {GE, GT, LE, LT, EQ, NE, SINGLE} op;
        Expression (Expression * e1, enum o _op, Expr * e2): expression(e1), expr(e2), op(_op) {
            this->is_leaf = false;
            this->name = "Expression";
        }
        Expression (Expr * e) : expr(e) {
            this->is_leaf = false;
            this->name = "Expression";
            op = SINGLE;
        }
        
        Expression * expression;
        Expr * expr;

        std::vector<Node *> get_descendants();
};

class Expr : public Node {
    public:
        enum o {PULS, MINUS, OR, SINGLE} op;
        Expr (Expr * e, enum o _op, Term * t): expr(e), term(t), op(_op) {
            this->is_leaf = false;
            this->name = "Expr";
        }
        Expr (Term *t) : term(t) {
            this->is_leaf = false;
            this->name = "Expr";
            op = SINGLE;
        }

        Expr * expr;
        Term * term;

        std::vector<Node *> get_descendants();
};

class Term : public Node {
    public:
        enum o {MUL, DIV, MOD, AND, SINGLE} op;
        Term (Term * t, enum o _op, Factor * f) : term(t), factor(f), op(_op) {
            this->is_leaf = false;
            this->name = "Term";
        }
        Term (Factor * f) : factor(f) {
            this->is_leaf = false;
            this->name = "Term"; 
            op = SINGLE;
        }

        Term * term;
        Factor * factor;

        std::vector<Node *> get_descendants();
};

class Factor : public Node {
    public:
        enum t {FUNC_WITH_NO_ARGS, 
                FUNC,
                CONST_VALUE, 
                EXPRESSION,
                NOT_FACTOR,
                MINUS_FACTOR,
                ARRAY,
                MEMBER
        } type;
        Factor (ID * i) : id1(i) {
            this->is_leaf = false;
            this->name = "Factor";
            type = FUNC_WITH_NO_ARGS;
        }
        Factor (ID * i, ArgsList * al) : id1(i), args_list(al) {
            this->is_leaf = false;
            this->name = "Factor";
            type = FUNC;
        }
        Factor (ConstValue * cv) : const_value(cv) {
            this->is_leaf = false;
            this->name = "Factor";
            type = CONST_VALUE;
        }
        Factor (Expression * e) : expr(e) {
            this->is_leaf = false;
            this->name = "Factor";
            type = EXPRESSION;
        }
        Factor (Factor * f, enum t ty) : factor(f), type(ty) {
            this->is_leaf = false;
            this->name = "Factor";
        }
        Factor (IDDotted * i, Expression * e) : idd(i), expr(e) {
            this->is_leaf = false;
            this->name = "Factor";
            type = ARRAY;
        }
        Factor (IDDotted * i) : idd(i){
            this->is_leaf = false;
            this->name = "Factor";
            type = MEMBER;
        }
        ~Factor() {}
        ID * id1;
        IDDotted * idd;
        ArgsList * args_list;
        ConstValue * const_value;
        Expression * expr;
        Factor * factor;

        std::vector<Node *> get_descendants();
};

class ArgsList : public Node {
    public:
        ArgsList () {}
        ~ArgsList () {}

        std::vector<Expression *> args_list;
        void add(Expression *);
        std::vector<Node *> get_descendants();
};

class ExprList: public Node {
    public:
        ExprList () {}
        ~ExprList () {}

        std::vector<Expression *> expr_list;
        void add(Expression *);
        std::vector<Node *> get_descendants();
};

#endif
