#ifndef ast_whileloop_hpp
#define ast_whileloop_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class whileloop : public Node {

    private:
        NodePtr con;            //condition
        NodePtr while_block;

    public:
        whileloop(NodePtr _con, NodePtr _while_block)
            :   con(_con),
                while_block(_while_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"while ( ";
            con->print(dst,span);
            dst<<" )"<<std::endl;
            while_block->print(dst,span+1);
            dst<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

#endif
