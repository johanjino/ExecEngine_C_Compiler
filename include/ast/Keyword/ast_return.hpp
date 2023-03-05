#ifndef ast_return_hpp
#define ast_return_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Return : public Node {

    private:
        NodePtr next;

    public:
        Return(NodePtr _next)
            : next(_next)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"return ";
            next->print(dst, span);
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }
};

#endif
