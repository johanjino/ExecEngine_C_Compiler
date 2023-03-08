#ifndef ast_shift_hpp
#define ast_shift_hpp

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
