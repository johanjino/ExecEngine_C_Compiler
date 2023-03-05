#ifndef ast_unary_hpp
#define ast_unary_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"

class Unary : public Node{
    private:
        NodePtr expr;
    protected:
        Unary(const NodePtr _expr)
            : expr(_expr)
        {}
    public:
        virtual ~Unary(){
            delete expr;
        }

        virtual const char *getOpcode() const =0;

        NodePtr getExpr() const
        { return expr; }

        virtual void print(std::ostream &dst, int span) const override
        {
            dst << "( ";
            dst << getOpcode();
            dst << " ";
            expr->print(dst, span);
            dst << " )";
        }
};

class NegOperator : public Unary{
    public:
        NegOperator(const NodePtr _expr)
            : Unary(_expr)
        {}

        virtual const char *getOpcode() const override
        { return "-"; }

        virtual double evaluate(
            const std::map<std::string, double> &bindings
        ) const override
        {
            return (-getExpr()->evaluate(bindings));
        }
};

#endif
