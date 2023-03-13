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

        virtual std::string getType(const std::map<std::string, std::vector<std::string>> &bindings = {}) const {
           return "NULL";
        }

        virtual std::string getClass() const{
            return "getClass not defined here or Wrong usage";
        }

        virtual std::string getId() const{
            return "getId not defined here or Wrong usage";
        }

        virtual long double getValue() const{
            std::cerr<< "getValue not defined here or Wrong usage"<<std::endl;
            exit(1);
        }

        //! Tell and expression to print itself to the given stream
        virtual void print(std::ostream &dst, int span) const =0;

        //! Evaluate the tree using the given mapping of variables to numbers
        virtual double evaluate(const std::map<std::string,double> &bindings) const{
            throw std::runtime_error("Not implemented.");
            }

        //! Generate RISC-V Assembly
        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const{
                dst<<"NOT IMPLEMENTED YET or ERROR ? HOW DID IT COME HERE?"<<std::endl;
        }
};


#endif
