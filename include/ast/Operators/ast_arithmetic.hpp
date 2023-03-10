#ifndef ast_arithmetic_hpp
#define ast_arithmetic_hpp

#include "ast_operator.hpp"

class AddOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "+"; }
    public:
        AddOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C : Run bin/eval_expr with something like 5+a, where a=10, to make sure you understand how this works
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"add "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};

class SubOperator : public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "-"; }
    public:
        SubOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}


        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-D : Implement this, based on AddOperator::evaluate
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl-vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};


class MulOperator : public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "*"; }
    public:
        MulOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl*vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"mul "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};

class DivOperator : public Operator {
    protected:
        virtual const char *getOpcode() const override
        { return "/"; }
    public:
        DivOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl/vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg();
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg();
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"div "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};



#endif
