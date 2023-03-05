#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Declaration : public Node{
    private:
        NodePtr type;
        NodePtr id;
        NodePtr value;
    public:
        Declaration (NodePtr _type, NodePtr _id, NodePtr _value)
            :   type(_type),
                id(_id),
                value(_value)
            {}

        virtual const char *getOpcode(){return "=";}

        NodePtr gettype() const
        { return type; }

        NodePtr getid() const
        { return id; }

        NodePtr getvalue() const
        { return value; }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            if (type!=NULL){
                type->print(dst,span);
            }
            id->print(dst, span);
            if (value!=NULL){
                dst<<"=";
                value->print(dst, span);
            }
            dst<<std::endl;
        }


};

#endif
