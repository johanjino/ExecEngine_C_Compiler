#ifndef ast_arrays_hpp
#define ast_arrays_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"

// | DATA_TYPES IDENTIFIER '[' EXPR ']'	{$$ = new Array_Declaration($1, $2, $4);}
	// | IDENTIFIER '[' EXPR ']'	{ $$ = new Array_Index($1, $3, NULL); }
	// | IDENTIFIER '[' EXPR ']' '=' EXPR { $$ = new Array_Index($1, $3, $6); }

class Array_Declaration : public Node {

    private:
        NodePtr type;
        NodePtr id;
        NodePtr size;

    public:
        Array_Declaration(NodePtr _type, NodePtr _id, NodePtr _size)
            :   type(_type),
                id(_id),
                size(_size)
        {}
        


        virtual const char *getOpcode(){return "=";}

        std::string gettype() const override
        { return (type!=NULL) ? type->gettype() : "NULL"; }

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return size; }



       virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            type->print(dst,span);
            id->print(dst, span);
            dst<<"[";
            size->print(dst, span);
            dst<<"]";
            dst<<std::endl;

       }

};


class Array_Index : public Node {

    private:
        NodePtr id;
        NodePtr index;
        NodePtr value;

    public:
        Array_Index(NodePtr _id, NodePtr _index, NodePtr _value)
            :   id(_id),
                index(_id),
                value(_value)
        {}


        virtual const char *getOpcode(){return "=";}

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return index; }

       virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            id->print(dst,span);
            dst<<"[";
            index->print(dst, span);
            dst<<"]";
            if (value != NULL){
                dst<<std::setw(span*4)<<" = ";
                value->print(dst,span+1);
            }
            dst<<std::endl;
       }

};







#endif
