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
                next->riscv_asm(dst, helper, destReg, bindings);
            }
            dst<<"jr ra"<<std::endl;
        }
};

class Continue : public Node {
    public:
        Continue()
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"continue ";
            dst<<std::endl;
        }
};

class Break : public Node {
    public:
        Break()
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"break ";
            dst<<std::endl;
        }
};

#endif
