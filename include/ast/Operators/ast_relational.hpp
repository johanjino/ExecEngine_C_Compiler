#ifndef ast_relational_hpp
#define ast_relational_hpp

#include "ast_operator.hpp"



class GthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">"; }
    public:
        GthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};

class LthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<"; }
    public:
        LthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};

class GthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">="; }
    public:
        GthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};


class LthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<="; }
    public:
        LthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};


class EqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "=="; }
    public:
        EqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};

class NEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "!="; }
    public:
        NEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }
};


#endif
