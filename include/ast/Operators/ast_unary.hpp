#ifndef ast_unary_hpp
#define ast_unary_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"

class Unary : public Node{
    protected:
        NodePtr expr;
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

        virtual std::string getType() const override{
            return expr->getType();
        }

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

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings,
            std::string datatype = "None")const override{

                //Calculate expr
                expr->riscv_asm(dst, helper, destReg, bindings);

                //Negate
                dst<<"neg "<<destReg<<", "<<destReg<<std::endl;

        }

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
