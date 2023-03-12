#ifndef ast_break_hpp
#define ast_break_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"

class Break : public Node {
    public:
        Break()
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"break ";
            dst<<std::endl;
        }

         virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                dst<<"beq zero, zero, "<<helper.get_loop_labels("End")<<std::endl;
            }
};
#endif
