#ifndef ast_forloop_hpp
#define ast_forloop_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class forloop : public Node {

    private:
        NodePtr init_cont;      //initialise control
        NodePtr con;            //condition
        NodePtr update_cont;    //update control
        NodePtr for_block;

    public:
        forloop(NodePtr _init_cont, NodePtr _con, NodePtr _update_cont, NodePtr _for_block)
            :   init_cont(_init_cont),
                con(_con),
                update_cont(_update_cont),
                for_block(_for_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"for ( ";
            init_cont->print(dst,span);
            dst<<"; ";
            con->print(dst,span);
            dst<<"; ";
            update_cont->print(dst,span);
            dst<<" )"<<std::endl;
            for_block->print(dst,span+1);
            dst<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

#endif
