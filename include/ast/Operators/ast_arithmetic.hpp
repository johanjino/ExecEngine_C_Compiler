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
                    bool pointer;
                    if (bindings.count(left->getId())){
                        if (bindings[left->getId()].size()>2){
                            pointer = true;
                        }
                    }
                    //Calculate Left
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings);

                    //Store the left value
                    std::string mem = helper.allocateMemory();
                    dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);

                    //Calculate Right
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings);
                    if (pointer){
                        std::string temp = helper.allocateReg(datatype);
                        dst<<"li "<<temp<<", 4"<<std::endl;
                        dst<<"mul "<<reg_right<<", "<<reg_right<<", "<<temp<<std::endl;
                        dst<<"addi "<<temp<<", zero, 0"<<std::endl;
                        helper.deallocateReg(temp);
                    }

                    //Load the left value
                    reg_left = helper.allocateReg(datatype);
                    dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                    helper.last_mem_allocated += helper.min_mem;

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
                if (datatype == "float"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fsub.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fsub.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else{
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
                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
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
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fmul.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fmul.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else{
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
                if (datatype == "float"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fdiv.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"fdiv.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else{
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
                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
        }
};

class ModOperator : public Operator {
    protected:
        virtual const char *getOpcode() const override
        { return "%"; }
    public:
        ModOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                if (datatype == "float"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"frem.s "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.s "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.s "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else if(datatype == "double" || datatype == "long double"){
                    std::string reg_left = helper.allocateReg(datatype);
                    left->riscv_asm(dst, helper, reg_left, bindings, datatype);
                    std::string reg_right = helper.allocateReg(datatype);
                    right->riscv_asm(dst, helper, reg_right, bindings, datatype);
                    dst<<"frem.d "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;
                    dst<<"fsub.d "<<reg_left<<", "<<reg_left<<", "<<reg_left<<std::endl;
                    dst<<"fsub.d "<<reg_right<<", "<<reg_right<<", "<<reg_right<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
                else{
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
                    dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_left);
                    helper.deallocateReg(reg_right);
                }
        }
};

#endif
