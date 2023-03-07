#ifndef ast_shift.hpp
#define ast_shift.hpp

#include "ast_operator.hpp"

class RightShiftOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">>"; }
    public:
        RightShiftOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
};

class LeftShiftOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<<"; }
    public:
        LeftShiftOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}
};

#endif
