#ifndef AST_H_ 
#define AST_H_

#include<string>
#include<vector>
#include<iostream>

class Node {
    public:
        Node(){}
        ~Node() {}

        bool is_leaf, is_root;
        std::string name;
        std::vector<Node *> descendants;
        
        void prt(){};
};

class Program : public Node {
    public:
        Program(){}
        ~Program(){}
        
};


#endif