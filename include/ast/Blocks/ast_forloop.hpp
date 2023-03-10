#ifndef ast_forloop_hpp
#define ast_forloop_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class forloop : public Node {

    private:
        NodePtr init_cont;      //initialise control
        NodePtr con;            //condition
        NodePtr update_cont;    //update control
        NodePtr for_block;

    public:
        forloop(NodePtr _init_cont, NodePtr _con, NodePtr _update_cont, NodePtr _for_block)
            :   init_cont(_init_cont),
                con(_con),
                update_cont(_update_cont),
                for_block(_for_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"for ( ";
            init_cont->print(dst,span);
            dst<<"; ";
            con->print(dst,span);
            dst<<"; ";
            update_cont->print(dst,span);
            dst<<" )"<<std::endl;
            for_block->print(dst,span+1);
            dst<<std::endl;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None") const override{

            //create labels
            std::string start_loop = helper.createLabel("start_for");
            std::string end_loop = helper.createLabel("end_for");

            //initialise condition
            init_cont->riscv_asm(dst,helper,destReg,bindings);

            //evalute conditon
            std::string condition_reg = helper.allocateReg();
            dst<<start_loop<<":"<<std::endl;
            con->riscv_asm(dst, helper, condition_reg, bindings);
            dst<<"beq "<<condition_reg<<", zero"<<", "<<end_loop<<std::endl; //could be made better. Make use of relational risc instructions

            //loop block
            if (for_block!=NULL){
                for_block->riscv_asm(dst,helper,destReg,bindings);
            }
            update_cont->riscv_asm(dst,helper,destReg,bindings);
            dst<<"beq zero, zero, "<<start_loop<<std::endl;

            //end loop
            dst<<end_loop<<":"<<std::endl;

            //clear registers
            if (init_cont->getType() != "NULL"){               // if control was intialised within loop construct -> need to earse it
                dst<<"addi "<<bindings[init_cont->getId()]<<", zero, 0"<<std::endl;
                bindings.erase(init_cont->getId());
            }
            dst<<"addi "<<condition_reg<<", zero, 0"<<std::endl;
            helper.deallocateReg(std::stoi(condition_reg.erase(0,1)));

        }
};

#endif
