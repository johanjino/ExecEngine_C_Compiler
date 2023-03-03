#ifndef ast_body_hpp
#define ast_body_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"


class Body : public Node {

    private:
        NodePtr next;

    public:
        Body(NodePtr _next)
            :   next(_next)
        {}


        virtual void print(std::ostream &dst) const override{
            next->print(dst);
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }
};

#endif
