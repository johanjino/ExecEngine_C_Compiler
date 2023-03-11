#ifndef ast_shift_hpp
#define ast_shift_hpp

#include "ast_operator.hpp"

class RightShiftOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">>"; }
    public:
        RightShiftOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"srl "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }
};

class LeftShiftOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<<"; }
    public:
        LeftShiftOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"sll "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }
};

#endif
