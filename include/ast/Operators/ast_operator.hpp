#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "../ast_node.hpp"


class Operator : public Node{
    private:
        NodePtr left;
        NodePtr right;
    protected:
        Operator(NodePtr _left, NodePtr _right)
            : left(_left)
            , right(_right)
        {}
    public:
        virtual ~Operator(){
            delete left;
            delete right;
        }

        virtual const char *getOpcode() const =0;

        NodePtr getLeft() const
        { return left; }

        NodePtr getRight() const
        { return right; }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<"( ";
            left->print(dst, span);
            dst<<" ";
            dst<<getOpcode();
            dst<<" ";
            right->print(dst, span);
            dst<<" )";
        }
};

#endif
