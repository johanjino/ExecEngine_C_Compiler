#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Declaration : public Node{
    private:
        NodePtr type;
        NodePtr id;
        NodePtr value;
    public:
        Declaration (NodePtr _type, NodePtr _id, NodePtr _value)
            :   type(_type),
                id(_id),
                value(_value)
            {}

        virtual const char *getOpcode(){return "=";}

        std::string getType() const override
        { return (type!=NULL) ? type->getType() : "NULL"; }

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return value; }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            if (type!=NULL){
                type->print(dst,span);
            }
            id->print(dst, span);
            if (value!=NULL){
                dst<<"=";
                value->print(dst, span);
            }
            dst<<std::endl;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                if (type!=NULL){
                    std::string reg = helper.allocateReg(datatype);
                    if (value!=NULL){
                        value->riscv_asm(dst, helper, reg, bindings, type->getType());
                    }
                    id->riscv_asm(dst, helper, reg, bindings, type->getType());
                    helper.deallocateReg(reg);
                }
                else{
                    if (bindings.count(id->getId())){
                        datatype = bindings[id->getId()][1];
                        if (datatype == "float" || datatype == "double" || datatype == "long double"){
                            std::string mem = bindings[id->getId()][0];
                            std::string reg = helper.allocateReg(datatype);
                            dst<<"flw "<<reg<<", "<<mem<<"(sp)"<<std::endl;
                            value->riscv_asm(dst, helper, reg, bindings, datatype);
                            dst<<"fsw "<<reg<<", "<<mem<<"(sp)"<<std::endl;
                            dst<<"fadd.s "<<destReg<<", "<<reg<<", f0"<<std::endl;     //assuming no one accesses f0 haha
                            dst<<"fsub.s "<<reg<<", "<<reg<<", "<<reg<<std::endl;
                            helper.deallocateReg(reg);
                        }
                        else{
                            std::string mem = bindings[id->getId()][0];
                            std::string reg = helper.allocateReg(datatype);
                            dst<<"lw "<<reg<<", "<<mem<<"(sp)"<<std::endl;
                            value->riscv_asm(dst, helper, reg, bindings);
                            dst<<"sw "<<reg<<", "<<mem<<"(sp)"<<std::endl;
                            dst<<"mv "<<destReg<<", "<<reg<<std::endl;
                            dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                            helper.deallocateReg(reg);
                        }
                    }
                    else{
                        std::cerr<< "Trying to access variable that does not exist"<<std::endl;
                        exit(1);
                    }
                }
            }


};

#endif
