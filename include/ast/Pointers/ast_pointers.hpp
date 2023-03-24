#ifndef ast_pointers_hpp
#define ast_pointers_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "../ast_node.hpp"


class Pointer_Init : public Node{

    protected:
        NodePtr var;

    public:
        Pointer_Init(NodePtr _var)
            : var(_var)
        {}

        virtual ~Pointer_Init(){
            delete var;
        }

        virtual std::string getId() const{
            return var->getId();
        }

        virtual std::string getClass() const override{
            return "Pointer";
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<" *";
            var->print(dst, span);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                    std::string mem = helper.allocateMemory();
                    dst<<"sw "<<destReg<<", "<<mem<<"(sp)"<<std::endl;

                    std::vector<std::string> properties;
                    properties.push_back(mem);
                    properties.push_back(datatype);
                    properties.push_back("p"); //to later identify the pointer
                    bindings[var->getId()] = properties;

        }
};

class Pointer_Call : public Node{

    protected:
        NodePtr var;

    public:
        Pointer_Call(NodePtr _var)
            : var(_var)
        {}

        virtual ~Pointer_Call(){
            delete var;
        }

        virtual std::string getId() const{
            return var->getId();
        }

        virtual std::string getClass() const override{
            return "Pointer";
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<" *";
            var->print(dst, span);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                    std::string reg = helper.allocateReg(datatype);
                    if (bindings[var->getId()][1] == "char"){
                        dst<<"lw "<<reg<<", "<<bindings[var->getId()][0]<<"(sp)"<<std::endl;
                        dst<<"lbu "<<destReg<<", 0("<<reg<<")"<<std::endl;
                    }
                    else{
                        dst<<"lw "<<reg<<", "<<bindings[var->getId()][0]<<"(sp)"<<std::endl;
                        dst<<"lw "<<destReg<<", 0("<<reg<<")"<<std::endl;
                    }
                    dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg);


        }
};

class Address : public Node{

    protected:
        NodePtr var;

    public:
        Address(NodePtr _var)
            : var(_var)
        {}

        virtual ~Address(){
            delete var;
        }

        virtual std::string getId() const{
            return "&";
        }


        virtual void print(std::ostream &dst, int span) const override{
            dst<<" &";
            var->print(dst, span);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                    std::string reg = helper.allocateReg(datatype);
                    dst<<"addi "<<reg<<", sp, "<<bindings[var->getId()][0]<<std::endl;
                    dst<<"add "<<destReg<<", "<<reg<<", zero"<<std::endl;
                    dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg);


        }
};

#endif
