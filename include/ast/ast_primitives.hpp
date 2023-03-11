#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <stdint.h>

#include "ast_node.hpp"




// For IEEE754 conversion
union {
    float f;
    uint32_t i;
} u;



class Variable : public Node {
    private:
        std::string id;
    public:
        Variable(const std::string &_id)
            : id(_id)
        {}

        virtual std::string getId() const override
        { return id; }

        virtual void print(std::ostream &dst, int span) const override
        {
            dst<<id;
        }

        virtual std::string getType(const std::map<std::string, std::vector<std::string>> &bindings = {}) const override{
            if (!bindings.empty()) {
                auto it = bindings.find(id);
                return it->second.at(1);
            }       //temporary fix only :( No time to fix everything
            return "Hope it doesnt get here!";
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

            std::string floating_repr = "";
            if (datatype == "float" || datatype == "double" || datatype == "long double"){
                floating_repr = "f";
            }
            if (bindings.count(id)){
                dst<<floating_repr<<"lw "<<destReg<<", "<<bindings[id][0]<<"(sp)"<<std::endl;
            }
            else{
                std::string mem = helper.allocateMemory();
                dst<<floating_repr<<"sw "<<destReg<<", "<<mem<<"(sp)"<<std::endl;
                std::vector<std::string> properties;
                properties.push_back(mem);
                properties.push_back(datatype);
                bindings[id] = properties;
            }

        }

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-B : Run bin/eval_expr with a variable binding to make sure you understand how this works.
            // If the binding does not exist, this will throw an error
            return bindings.at(id);
        }
};

class Number : public Node {
    private:
        long double value;
    public:
        Number(long double _value)
            : value(_value)
        {}

        std::string getClass() const override{
            return "Number";
        }

        long double getValue() const override{
            return value;
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<value;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

            if (datatype == "int" || datatype == "None"){

            }
            else if(datatype == "unsigned int"){

            }
            else if(datatype == "long"){

            }
            else if(datatype == "unsigned long"){

            }
            else if(datatype == "char"){

            }
            else if(datatype == "unsigned char"){

            }
            else if(datatype == "signed char"){

            }
            else if(datatype == "short"){

            }
            else if(datatype == "unsigned short"){

            }
            else if(datatype == "float"){
                //float value = (value);
                u.f = value;

                std::string reg = helper.allocateReg("int");
                dst<<"li "<<reg<<", "<<(u.i)<<std::endl;
                dst<<"sw "<<reg<<", 0(sp)"<<std::endl;      //not ideal, can cause memory loss if 0(sp) occupied
                dst<<"flw "<<destReg<<", 0(sp)"<<std::endl;
                dst<<"addi "<<reg<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg);
                return;
            }
            else if(datatype == "double"){
                double value = (value);
                u.f = value;
                value = u.i;
            }
            else if(datatype == "long double"){
                long double value = (value);
                u.f = value;
                value = u.i;
                //Just seems too hard. Dont think i am capable of doing this
            }
            else {
                std::cerr<<datatype<<": is an invalid Data Type for a number!"<<std::endl;
                exit(1);
            }

            dst<<"li "<<destReg<<", "<<(value)<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            return value;
        }




};


#endif
