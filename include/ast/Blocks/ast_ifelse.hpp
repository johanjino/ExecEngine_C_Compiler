#ifndef ast_ifelse_hpp
#define ast_ifelse_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class ifelse : public Node {

    private:
        NodePtr con;
        NodePtr if_block;
        NodePtr else_block;

    public:
        ifelse(NodePtr _con, NodePtr _if_block, NodePtr _else_block)
            :   con(_con),
                if_block(_if_block),
                else_block(_else_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"if ( ";
            con->print(dst,span);
            dst<<" )"<<std::endl;
            if_block->print(dst,span+1);
            dst<<std::endl;

        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }


        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const override{

            //create labels
            std::string end_of_ifelse = helper.createLabel("end_of_ifelse");
            std::string else_part = helper.createLabel("else_block");

            //evalute conditon
            std::string condition_reg = helper.allocateReg(datatype);
            con->riscv_asm(dst, helper, condition_reg, bindings);
            dst<<"beq "<<condition_reg<<", zero"<<", "<<else_part<<std::endl; //could be made better. Make use of relational risc instructions

            //if block
            if (if_block!=NULL){
                if_block->riscv_asm(dst,helper,destReg,bindings);
            }
            dst<<"beq zero, zero, "<<end_of_ifelse<<std::endl;

            //else block
            dst<<else_part<<":"<<std::endl;
            if (else_block!=NULL){
                else_block->riscv_asm(dst,helper,destReg,bindings);
            }
            dst<<"beq zero, zero, "<<end_of_ifelse<<std::endl;

            //end of ifelse
            dst<<end_of_ifelse<<":"<<std::endl;

            //clear registers
            dst<<"addi "<<condition_reg<<", zero, 0"<<std::endl;
            helper.deallocateReg(condition_reg);

        }
};

#endif
