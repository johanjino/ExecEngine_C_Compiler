#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_node.hpp"

#include <cmath>

class Function
    : public Node
{
private:
    NodePtr arg;
protected:
    Function(NodePtr _arg)
        : arg(_arg)
    {}
public:
    virtual ~Function()
    {
        delete arg;
    }

    virtual const char * getFunction() const =0;

    NodePtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<getFunction()<<"( ";
        arg->print(dst);
        dst<<" )";
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // NOTE : This should be implemented by the inheriting function nodes, e.g. LogFunction
        throw std::runtime_error("FunctionOperator::evaluate is not implemented.");
    }
};


#endif
