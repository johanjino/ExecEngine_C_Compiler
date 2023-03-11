#ifndef ast_logical_hpp
#define ast_logical_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class OrOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "||"; }
    public:
        OrOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);

                dst<<"seqz "<<reg_left<<", "<<reg_left<<std::endl;
                dst<<"seqz "<<reg_left<<", "<<reg_left<<std::endl; // inverting logic to correct it, think!!!
                dst<<"seqz "<<reg_right<<", "<<reg_right<<std::endl;
                dst<<"seqz "<<reg_right<<", "<<reg_right<<std::endl; // inverting logic to correct it, think!!!
                dst<<"or "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }



};

class AndOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&&"; }
    public:
        AndOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                                 
                dst<<"seqz "<<reg_left<<", "<<reg_left<<std::endl;
                dst<<"seqz "<<reg_left<<", "<<reg_left<<std::endl; // inverting logic to correct it, think!!!
                dst<<"seqz "<<reg_right<<", "<<reg_right<<std::endl;
                dst<<"seqz "<<reg_right<<", "<<reg_right<<std::endl; // inverting logic to correct it, think!!!
                dst<<"and "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }

};

class NotOperator: public Node{
    private:
        NodePtr value;
    protected:
        virtual const char *getOpcode() const
        { return "!"; }
    public:
        NotOperator(NodePtr _value)
            : value(_value)
        {}

        virtual void print(std::ostream &dst, int span) const override{
            dst<<"( ";
            dst<<getOpcode();
            value->print(dst, span);
            dst<<" )";
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg = helper.allocateReg();
                value->riscv_asm(dst, helper, reg, bindings);
                dst<<"seqz "<<destReg<<", "<<reg<<std::endl;
                dst<<"andi "<<destReg<<", "<<destReg<<", "<<"0xff"<<std::endl; //lets us preserve the LSByte only!!!
                dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg.erase(0,1)));
        }
};

#endif
