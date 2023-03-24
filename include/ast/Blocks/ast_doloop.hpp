#ifndef ast_doloop_hpp
#define ast_doloop_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class doloop : public Node {

    private:
        NodePtr while_block;
        NodePtr con;            //condition

    public:
        doloop(NodePtr _while_block, NodePtr _con)
            :   while_block(_while_block),
                con(_con)
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
            std::string start_loop = helper.createLabel("start_do");
            std::string end_loop = helper.createLabel("end_do");
            helper.new_loop(start_loop, end_loop);

            //evalute conditon
            std::string condition_reg = helper.allocateReg("None");  //this is not ideal, prevents unwanted float regs being used
            dst<<start_loop<<":"<<std::endl;

            //loop block
            if (while_block!=NULL){
                while_block->riscv_asm(dst,helper,destReg,bindings);
            }
            con->riscv_asm(dst, helper, condition_reg, bindings);
            dst<<"bne "<<condition_reg<<", zero"<<", "<<start_loop<<std::endl; //could be made better. Make use of relational risc instructions

            //end loop
            dst<<end_loop<<":"<<std::endl;
            helper.exit_loop();


            //clear registers
            dst<<"addi "<<condition_reg<<", zero, 0"<<std::endl;
            helper.deallocateReg(condition_reg);
        }
};

#endif
