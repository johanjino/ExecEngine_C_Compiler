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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"srl "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"sll "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"add "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"mul "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"div "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"rem "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"and "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"xor "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);
                dst<<"or "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));
        }

};

#endif
