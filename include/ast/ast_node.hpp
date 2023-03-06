#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <iomanip>

#include <memory>


#include "ast_helper.hpp"

class Node;

typedef const Node *NodePtr;

class Node {
    public:
        virtual ~Node(){
        }


        virtual std::string getClass() const{
            return "getClass not defined here or Wrong usage";
        }

        virtual double getValue() const{
        }

        //! Tell and expression to print itself to the given stream
        virtual void print(std::ostream &dst, int span) const =0;

        //! Evaluate the tree using the given mapping of variables to numbers
        virtual double evaluate(const std::map<std::string,double> &bindings) const{
            throw std::runtime_error("Not implemented.");
            }

        //! Generate RISC-V Assembly
        virtual void riscv_gen(std::ostream &dst, Helper &helper, std::string destReg) const{
        }
};


#endif
