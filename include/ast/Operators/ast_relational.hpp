#ifndef ast_relational_hpp
#define ast_relational_hpp

#include "ast_operator.hpp"



class GthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">"; }
    public:
        GthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //>
                dst<<"sgt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};

class LthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<"; }
    public:
        LthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //<
                dst<<"slt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};

class GthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">="; }
    public:
        GthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //>=
                dst<<"slt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"xori "<<destReg<<", "<<destReg<<", 1"<<std::endl;     //bitwise xor i.e. invert


                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};


class LthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<="; }
    public:
        LthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //<=
                dst<<"sgt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"xori "<<destReg<<", "<<destReg<<", 1"<<std::endl;    //bitwise xor i.e. invert


                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};


class EqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "=="; }
    public:
        EqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //>=
                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"seqz "<<destReg<<", "<<destReg<<std::endl;     //set equal 0


                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};

class NEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "!="; }
    public:
        NEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
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

                //>=
                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"snez "<<destReg<<", "<<destReg<<std::endl;     //set not equal 0


                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(std::stoi(reg_left.erase(0,1)));
                helper.deallocateReg(std::stoi(reg_right.erase(0,1)));

        }
};


#endif
