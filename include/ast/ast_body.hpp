#ifndef ast_body_hpp
#define ast_body_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"
#include "ast_listnode.hpp"


class Block : public Node {

    private:
        ListPtr branches;

    public:
        Block(ListPtr _branches)
            :   branches(_branches)
        {}


        virtual void print(std::ostream &dst) const override{
            dst<<"Block"<<std::endl;
            for (int i = 0; i < (branches)->size(); i++) {
                (*branches)[i]->print(dst);
            }
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

class Body : public Node {

    private:
        NodePtr next;
        std::vector<NodePtr> branches;

    public:
        Body(NodePtr _next, std::vector<NodePtr> &_branches)
            :   next(_next),
                branches(_branches)
        {branches.push_back(_next);}

        virtual std::vector<NodePtr> find_branches(){
            return branches;
        }

        virtual void print(std::ostream &dst) const override{
            dst<<"Body ";
            for(int i=0; i<branches.size(); i++){
                branches[i]->print(dst);
            }
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            //return next->evaluate(bindings);
        }
};

#endif
