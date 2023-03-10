#ifndef ast_struct_union_hpp
#define ast_struct_union_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"

	// | STRUCT_UNION IDENTIFIER '{' STRUCT_UNION_BODY '}'	{$$ = new Struct_Union_Declaration((new Variable(*$2)), $4);}

	// | IDENTIFIER '.' IDENTIFIER 		 { $$ = new Struct_Union_Access((new Variable(*$1)), (new Variable(*$3)), NULL); }
	// | IDENTIFIER '.' IDENTIFIER '=' EXPR { $$ = new Struct_Union_Access((new Variable(*$1)), (new Variable(*$3)), $5); }
class Struct_Union_Declaration : public Node {

    private:
        NodePtr id;
        ListPtr body;

    public:
        Struct_Union_Declaration(NodePtr _id, ListPtr _body)
            :   id(_id),
                body(_body)
        {}


        virtual const char *getOpcode(){return "=";}

        std::string getType() const override
        { return (id!=NULL) ? id->getType() : "NULL"; }

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return id; }



       virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            id->print(dst,span);
            id->print(dst, span);
            dst<<"[";
            id->print(dst, span);
            dst<<"]";
            dst<<std::endl;

       }

};

class Struct_Union_Access : public Node {

    private:
        NodePtr type;
        NodePtr id;
        NodePtr size;

    public:
        Struct_Union_Access(NodePtr _type, NodePtr _id, NodePtr _size)
            :   type(_type),
                id(_id),
                size(_size)
        {}



        virtual const char *getOpcode(){return "=";}

        std::string getType() const override
        { return (type!=NULL) ? type->getType() : "NULL"; }

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


#endif
