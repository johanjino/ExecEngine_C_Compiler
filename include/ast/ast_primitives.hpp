#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <stdint.h>

#include "ast_node.hpp"



// For datatype conversion
template<typename T>
T convert(long double value) {
    return static_cast<T>(value);       //allows explicit converison
};

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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

            std::string floating_repr = "";
            if (datatype == "float" || datatype == "double" || datatype == "long double"){
                floating_repr = "f";
            }
            if (bindings.count(id)){
                dst<<floating_repr<<"lw "<<floating_repr<<destReg<<", "<<bindings[id]<<"(sp)"<<std::endl;
            }
            else{
                std::string mem = helper.allocateMemory();
                dst<<floating_repr<<"sw "<<floating_repr<<destReg<<", "<<mem<<"(sp)"<<std::endl;
                bindings[id] = mem;
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
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

            if (datatype == "int" || datatype == "None"){
                int value = convert<int>(value);
            }
            else if(datatype == "unsigned int"){
                unsigned value = convert<unsigned int>(value);
            }
            else if(datatype == "long"){
                long value = convert<long>(value);
            }
            else if(datatype == "unsigned long"){
                unsigned long value = convert<unsigned long>(value);
            }
            else if(datatype == "char"){
                char value = convert<char>(value);
            }
            else if(datatype == "unsigned char"){
                unsigned char value = convert<unsigned char>(value);
            }
            else if(datatype == "signed char"){
                signed char value = convert<signed char>(value);
            }
            else if(datatype == "short"){
                short value = convert<short>(value);
            }
            else if(datatype == "unsigned short"){
                unsigned short value = convert<unsigned short>(value);
            }
            else if(datatype == "float"){
                float value = convert<float>(value);
                u.f = value;
                value = u.i;

            }
            else if(datatype == "double"){
                double value = convert<double>(value);
                u.f = value;
                value = u.i;
            }
            else if(datatype == "long double"){
                long double value = convert<long double>(value);
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
