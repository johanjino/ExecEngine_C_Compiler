#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Declaration : public Node{
    private:
        NodePtr id;
        NodePtr value;
    public:
        Declaration (NodePtr _id, NodePtr _value)
            :   id(_id),
                value(_value)
            {}

        virtual const char *getOpcode(){return "=";}

        NodePtr getid() const
        { return id; }

        NodePtr getvalue() const
        { return value; }

        virtual void print(std::ostream &dst) const override{
            id->print(dst);
            dst<<"=";
            value->print(dst);
        }

};

#endif
