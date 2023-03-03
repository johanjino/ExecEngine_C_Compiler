#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Node;

typedef const Node *NodePtr;

class Node {
    public:
        virtual ~Node(){
        }

        //! Tell and expression to print itself to the given stream
        virtual void print(std::ostream &dst) const =0;

        //! Evaluate the tree using the given mapping of variables to numbers
        virtual double evaluate(const std::map<std::string,double> &bindings) const{
            throw std::runtime_error("Not implemented.");
            }
};


#endif
