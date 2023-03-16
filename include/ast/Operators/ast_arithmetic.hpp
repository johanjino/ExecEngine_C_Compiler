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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                if (datatype == "float"){
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);

                    //Add
                    dst<<"fadd.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);

                    //Add
                    dst<<"fadd.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else{
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings);

                    std::string mem = helper.allocateMemory();
                    dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings);

                    //Load the left value
                    reg_left = helper.allocateReg(datatype);
                    dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                    helper.last_mem_allocated + helper.min_mem;

                    //Add
                    dst<<"add "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }

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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"sub "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                if (datatype == "float"){
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);

                    //Mul
                    dst<<"fmul.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);

                    //Add
                    dst<<"fmul.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);

                }
                else{
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings);

                    //Mul
                    dst<<"mul "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }

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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                //Calculate Left
                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);

                //Calculate Right
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);

                //Add
                dst<<"div "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};



#endif
