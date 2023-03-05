#ifndef ast_arithmetic_hpp
#define ast_arithmetic_hpp

#include "ast_operator.hpp"

class AddOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "+"; }
    public:
        AddOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C : Run bin/eval_expr with something like 5+a, where a=10, to make sure you understand how this works
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};

class SubOperator : public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "-"; }
    public:
        SubOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-D : Implement this, based on AddOperator::evaluate
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl-vr;
        }
};


class MulOperator : public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "*"; }
    public:
        MulOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl*vr;
        }
};

class DivOperator : public Operator {
    protected:
        virtual const char *getOpcode() const override
        { return "/"; }
    public:
        DivOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl/vr;
        }
};



#endif
