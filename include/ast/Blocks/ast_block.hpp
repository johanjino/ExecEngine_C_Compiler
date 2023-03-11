#ifndef ast_block_hpp
#define ast_block_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class Block : public Node {

    private:
        ListPtr branches;

    public:
        Block(ListPtr _branches)
            :   branches(_branches)
        {}

        virtual std::string getId() const override{
            return "Block";
        }

        virtual void print(std::ostream &dst, int span) const override{
            //dst<<std::setw(span*4)<<"Block"<<std::endl;
            for (int i = (branches)->size(); i > 0; i--) {
                (*branches)[i-1]->print(dst, span+1);
            }
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
            for (int i = (branches)->size(); i > 0; i--) {
                if ((*branches)[i-1]->getId() == "Block"){
                    helper.newScope(dst, false);    //entering new scope
                    (*branches)[i-1]->riscv_asm(dst, helper, destReg, bindings, datatype);
                    helper.exitScope(dst, false);   //exiting current scope
                    continue;
                }
                else if ((*branches)[i-1]->getId() == "Operator"){
                    //this is done so that if assignment operator is called implicitly, and not through decleration, it does not overwrite destReg.
                    //This is not an ideal solution
                    std::string temp = helper.allocateReg("int");
                    (*branches)[i-1]->riscv_asm(dst, helper, temp, bindings, datatype);
                    dst<<"addi "<<temp<<", zero, 0"<<std::endl;
                    helper.deallocateReg(temp);
                    continue;
                }
                (*branches)[i-1]->riscv_asm(dst, helper, destReg, bindings, datatype);
            }
        }
};

#endif
