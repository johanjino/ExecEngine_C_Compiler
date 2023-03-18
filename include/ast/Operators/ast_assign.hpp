#ifndef ast_assign_hpp
#define ast_assign_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class RightAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">>="; }
    public:
        RightAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"srl "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst <<"sw "<<destReg<< ", "<<bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }


};

class LeftAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<<="; }
    public:
        LeftAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"sll "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst <<"sw "<<destReg<<", "<<bindings[left->getId()][0]<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

class AddAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "+="; }
    public:
        AddAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"add "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst <<"sw "<<destReg<<", "<<bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }
};

class SubAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "-="; }
    public:
        SubAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst <<"sw "<<destReg<<", "<<bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

class MulAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "*="; }
    public:
        MulAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"mul "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst <<"sw "<<destReg<<", "<< bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

class DivAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "/="; }
    public:
        DivAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"div "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"sw " <<destReg<<", "<< bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

class ModAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "%="; }
    public:
        ModAssignOperator(NodePtr _left, NodePtr _right)
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

                dst<<"rem "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"sw "<<destReg<<", "<<bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }


};

class AndAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&="; }
    public:
        AndAssignOperator(NodePtr _left, NodePtr _right)
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
                dst<<"sw "<<destReg<<", "<<bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }


};

class XorAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "^="; }
    public:
        XorAssignOperator(NodePtr _left, NodePtr _right)
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
                dst<<"sw "<<destReg<<", "<< bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }


};

class OrAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "|="; }
    public:
        OrAssignOperator(NodePtr _left, NodePtr _right)
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
                dst<<"sw "<<destReg<<", "<< bindings[left->getId()][0]<<"(sp)"<< std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);
        }

};

#endif
