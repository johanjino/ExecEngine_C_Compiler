#ifndef ast_throwaway_hpp
#define ast_throwaway_hpp

#include <string>
#include <iostream>
#include <stdint.h>

#include "ast_node.hpp"

//Just to avoid segmetation fault in code we dont need assmebly

class Throwaway : public Node {
    public:
        Throwaway(){}

        virtual std::string getId() const override
        { return "NULL"; }

        virtual void print(std::ostream &dst, int span) const override{
        }


        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

            }
};


#endif
