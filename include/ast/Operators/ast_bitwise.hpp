#ifndef ast_bitwise.hpp
#define ast_bitwise.hpp

#include "../ast_node.hpp"
#include "ast_operator.hpp"

class AndBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "&"; }
    public:
        AndBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
};

class OrBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "|"; }
    public:
        OrBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
};

class XorBitwiseOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "^"; }
    public:
        XorBitwiseOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
};



#endif
