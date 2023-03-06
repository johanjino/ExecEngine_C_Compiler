#ifndef ast_output_hpp
#define ast_output_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"
#include "ast_listnode.hpp"

class Output : public Node {
    private:
        ListPtr functions;
    public:
        Output(ListPtr _functions)
            : functions(_functions)
        {}

        virtual void print(std::ostream &dst, int span) const override{
            for (int i = 0; i<(functions)->size(); i++) {
                (*functions)[i]->print(dst, span);
            }
        }

        virtual void riscv_gen(std::ostream &dst, Helper &helper, std::string destReg) const override{
            for (int i = 0; i<(functions)->size(); i++) {
                (*functions)[i]->riscv_gen(dst,helper,destReg);
            }
        }

};


#endif
