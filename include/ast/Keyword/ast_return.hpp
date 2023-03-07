#ifndef ast_return_hpp
#define ast_return_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Return : public Node {

    private:
        NodePtr next;

    public:
        Return(NodePtr _next)
            : next(_next)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"return ";
            if (next!=NULL){
                next->print(dst, span);
            }
            dst<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }


        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings)const override{
            if (next!=NULL){
                std::string reg = helper.allocateReg();
                next->riscv_asm(dst, helper, reg, bindings);
                dst<<"mv "<<destReg<<", "<<reg<<std::endl;
                dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg.erase(0,1)));
            }

        }
};

#endif
