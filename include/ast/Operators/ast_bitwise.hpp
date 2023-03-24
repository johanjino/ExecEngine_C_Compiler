#ifndef ast_bitwise_hpp
#define ast_bitwise_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class AndBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&"; }
    public:
        AndBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                dst<<"and "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }
};

class OrBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "|"; }
    public:
        OrBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
            virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                dst<<"or "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }
};

class XorBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "^"; }
    public:
        XorBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
            virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                dst<<"xor "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

class NotBitwiseOperator: public Node{
    private:
        NodePtr value;
    protected:
        virtual const char *getOpcode() const
        { return "~"; }
    public:
        NotBitwiseOperator(NodePtr _value)
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
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                std::string reg = helper.allocateReg(datatype);
                value->riscv_asm(dst, helper, reg, bindings);
                dst<<"not "<<destReg<<", "<<reg<<std::endl;
                dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg);
        }
};

#endif
