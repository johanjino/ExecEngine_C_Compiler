#ifndef ast_enum_hpp
#define ast_enum_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"

class Enum_Declaration : public Node {
    private:
        NodePtr id;
        ListPtr body;
    public:
        Enum_Declaration(NodePtr _id, ListPtr _body)
            :   id(_id),
                body(_body)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"enum ";
            id->print(dst,span);
            dst<<" {"<<std::endl;
            dst<<std::setw(span*4)<<std::endl;
            for (int i = (body)->size(); i > 0; i--) {
                (*body)[i-1]->print(dst, span+1);
            }
            dst<<" }"<<std::endl;
        }
};

#endif
