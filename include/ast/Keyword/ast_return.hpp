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
        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
            if (next!=NULL){
                next->riscv_asm(dst, helper, destReg, bindings, datatype);
            }
            dst<<"beq zero, zero, "<<helper.getfunctionEnd()<<std::endl;
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
