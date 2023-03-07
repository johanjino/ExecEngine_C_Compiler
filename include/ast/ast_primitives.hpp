#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

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
            std::map<std::string, std::string> &bindings)const override{
            if (bindings.count(id)){
                dst<<"add "<<destReg<<", zero, "<<bindings[id]<<std::endl;
            }
            else{
                dst<<"addi "<<destReg<<", zero, 0"<<std::endl;

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
        int value;
    public:
        Number(int _value)
            : value(_value)
        {}

        std::string getClass() const override{
            return "Number";
        }

        double getValue() const override{
            return value;
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<value;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings)const override{
            dst<<"li "<<destReg<<", "<<std::to_string(value)<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            return value;
        }




};


#endif
