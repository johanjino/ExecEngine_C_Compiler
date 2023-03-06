#ifndef ast_assign_hpp
#define ast_assign_hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class RightAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">>="; }
    public:
        RightAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // shift operations can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp  = static_cast<int>(vr);
        vl_temp >>= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

class LeftAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<<="; }
    public:
        LeftAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // shift operations can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp = static_cast<int>(vr);
        vl_temp <<= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

class AddAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "+="; }
    public:
        AddAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        vl += vr;
        return vl;
        }
};

class SubAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "-="; }
    public:
        SubAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        vl -= vr;
        return vl;
        }
};

class MulAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "*="; }
    public:
        MulAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        vl *= vr;
        return vl;
        }
};

class DivAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "/="; }
    public:
        DivAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        vl /= vr;
        return vl;
        }
};

class ModAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "%="; }
    public:
        ModAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // mod operation can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp = static_cast<int>(vr);
        vl_temp %= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

class AndAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&="; }
    public:
        AndAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // logical (AND, OR, XOR) operation can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp = static_cast<int>(vr);
        vl_temp &= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

class XorAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "^="; }
    public:
        XorAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // logical (AND, OR, XOR) operation can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp = static_cast<int>(vr);
        vl_temp ^= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

class OrAssignOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "|="; }
    public:
        OrAssignOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
        // NOTE:
        // logical (AND, OR, XOR) operation can only be applied to integral data types
        double vl = getLeft()->evaluate(bindings);
        double vr = getRight()->evaluate(bindings);

        int vl_temp = static_cast<int>(vl);
        int vr_temp = static_cast<int>(vr);
        vl_temp |= vr_temp;
        return static_cast<double>(vl_temp);
        }
};

#endif
