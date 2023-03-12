#ifndef ast_continue_hpp
#define ast_continue_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"



class Continue : public Node {
    public:
        Continue()
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"continue ";
            dst<<std::endl;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                std::string label = helper.get_loop_labels("Update");
                if (label == "None"){
                    //in while loop then -> use "Start" instead
                    label = helper.get_loop_labels("Start");
                }
                dst<<"beq zero, zero, "<<label<<std::endl;
            }
};


#endif
