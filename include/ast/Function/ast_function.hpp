#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class FunctionDef : public Node {

    private:
        NodePtr type;
        std::string name;
        ListPtr params;
        NodePtr next;

    public:
        FunctionDef(NodePtr _type, std::string* _name, ListPtr _params, NodePtr _next)
            :   type(_type),
                name(*_name),
                params(_params),
                next(_next)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            type->print(dst,span);
            dst<<name<<"( ";
            if (params!=NULL){
                for (int i = 0; i<params->size(); i++) {
                    (*params)[i]->print(dst, span);
                }
            }
            dst<<" )"<<std::endl;
            if (next!=NULL){
                next->print(dst, span);
            }
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }

        virtual void riscv_gen(std::ostream &dst, Helper &helper, std::string destReg)const override{
            dst<<name<<":"<<std::endl;
            if (params!=NULL){
                for (int i = 0; i<params->size(); i++) {
                    dst<<"  "<<"Parameters not implemeted in codegen yet :(";
                }
            }
            if (next!=NULL){
                next->riscv_gen(dst, helper, destReg);
            }

        }

};


class FunctionCall : public Node {

    private:
        std::string name;
        ListPtr args;

    public:
        FunctionCall(std::string* _name, ListPtr _args)
            :   name(*_name),
                args(_args)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<" "<<name<<"( ";
            if (args!=NULL){
                for (int i = 0; i<args->size(); i++) {
                    (*args)[i]->print(dst, span);
                }
            }
            dst<<" )"<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

#endif
