#ifndef ast_logical_hpp
#define ast_logical_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class OrOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "||"; }
    public:
        OrOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return (vl || vr);
        }
};

class AndOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&&"; }
    public:
        AndOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return (vl && vr);
        }
};

class NotOperator: public Node{
    private:
        NodePtr value;
    protected:
        virtual const char *getOpcode() const
        { return "!"; }
    public:
        NotOperator(NodePtr _value)
            : value(_value)
        {}

        virtual void print(std::ostream &dst, int span) const override{
            dst<<"( ";
            dst<<getOpcode();
            value->print(dst, span);
            dst<<" )";
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // TODO-C :  evaluate functions not in use at the moment
            double vl=evaluate(bindings);
            return (!vl);
        }

};

#endif
