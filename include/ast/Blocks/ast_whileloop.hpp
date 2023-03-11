#ifndef ast_whileloop_hpp
#define ast_whileloop_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class whileloop : public Node {

    private:
        NodePtr con;            //condition
        NodePtr while_block;

    public:
        whileloop(NodePtr _con, NodePtr _while_block)
            :   con(_con),
                while_block(_while_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"while ( ";
            con->print(dst,span);
            dst<<" )"<<std::endl;
            while_block->print(dst,span+1);
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
            std::string start_loop = helper.createLabel("start_while");
            std::string end_loop = helper.createLabel("end_while");

            //evalute conditon
            std::string condition_reg = helper.allocateReg("None");  //this is not ideal, prevents unwanted float regs being used
            dst<<start_loop<<":"<<std::endl;
            con->riscv_asm(dst, helper, condition_reg, bindings);
            dst<<"beq "<<condition_reg<<", zero"<<", "<<end_loop<<std::endl; //could be made better. Make use of relational risc instructions

            //loop block
            if (while_block!=NULL){
                while_block->riscv_asm(dst,helper,destReg,bindings);
            }
            dst<<"beq zero, zero, "<<start_loop<<std::endl;

            //end loop
            dst<<end_loop<<":"<<std::endl;

            //clear registers
            dst<<"addi "<<condition_reg<<", zero, 0"<<std::endl;
            helper.deallocateReg(condition_reg);
        }
};

#endif
