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

};

class IncOperator_Post : public Unary{
    public:
        IncOperator_Post(const NodePtr _expr)
            : Unary(_expr)
        {}

        virtual const char *getOpcode() const override
        { return "++"; }

        virtual void print(std::ostream &dst, int span) const override
        {
            dst << "( ";
            getExpr()->print(dst, span);
            dst << " ";
            dst << getOpcode();
            dst << " )";
        }
};

class IncOperator_Pre : public Unary{
    public:
        IncOperator_Pre(const NodePtr _expr)
            : Unary(_expr)
        {}

        virtual const char *getOpcode() const override
        { return "++"; }

};

class DecOperator_Post : public Unary{
    public:
        DecOperator_Post(const NodePtr _expr)
            : Unary(_expr)
        {}

        virtual const char *getOpcode() const override
        { return "--"; }

        virtual void print(std::ostream &dst, int span) const override
        {
            dst << "( ";
            getExpr()->print(dst, span);
            dst << " ";
            dst << getOpcode();
            dst << " )";
        }
};

class DecOperator_Pre : public Unary{
    public:
        DecOperator_Pre(const NodePtr _expr)
            : Unary(_expr)
        {}

        virtual const char *getOpcode() const override
        { return "--"; }
};

#endif
