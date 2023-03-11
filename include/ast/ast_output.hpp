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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const override{
            for (int i = 0; i<(functions)->size(); i++) {
                datatype = (*functions)[i]->getType();
                if (datatype == "float" || datatype == "double" || datatype == "long double"){
                    (*functions)[i]->riscv_asm(dst,helper,"fa0", bindings, datatype);
                }
                else{
                    (*functions)[i]->riscv_asm(dst,helper,"a0", bindings, datatype);
                }
            }
        }

};


#endif
