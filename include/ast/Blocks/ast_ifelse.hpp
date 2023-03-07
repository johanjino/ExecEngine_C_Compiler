#ifndef ast_ifelse_hpp
#define ast_ifelse_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class ifelse : public Node {

    private:
        NodePtr con;
        NodePtr if_block;
        NodePtr else_block;

    public:
        ifelse(NodePtr _con, NodePtr _if_block, NodePtr _else_block)
            :   con(_con),
                if_block(_if_block),
                else_block(_else_block)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"if ( ";
            con->print(dst,span);
            dst<<" )"<<std::endl;
            if_block->print(dst,span+1);
            dst<<std::endl;
            if (else_block != NULL){
                dst<<std::setw(span*4)<<"else"<<std::endl;
                else_block->print(dst,span+1);
            }
        }

};

#endif
