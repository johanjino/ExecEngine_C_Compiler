#ifndef ast_block_hpp
#define ast_block_hpp

#include <string>
#include <iostream>
#include <vector>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class Block : public Node {

    private:
        ListPtr branches;

    public:
        Block(ListPtr _branches)
            :   branches(_branches)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"Block"<<std::endl;
            for (int i = (branches)->size(); i > 0; i--) {
                (*branches)[i-1]->print(dst, span+1);
            }
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

#endif
