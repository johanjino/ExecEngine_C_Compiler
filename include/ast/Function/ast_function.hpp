#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Function : public Node {

    private:
        std::string name;
        NodePtr next;

    public:
        Function(std::string* _name, NodePtr _next)
            :   name(*_name),
                next(_next)
        {}


        virtual void print(std::ostream &dst) const override{
            dst<<name<<"()"<<std::endl;
            next->print(dst);
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }
};

#endif
