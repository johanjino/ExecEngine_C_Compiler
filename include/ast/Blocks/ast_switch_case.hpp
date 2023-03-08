#ifndef ast_switch_case_hpp
#define ast_switch_case_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class switch_statement : public Node {
    private:
        NodePtr case_expr;
        NodePtr block;
    public:
        switch_statement(NodePtr _case_expr, NodePtr _block)
            :   case_expr(_case_expr),
                block(_block)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"switch ( ";
            case_expr->print(dst,span);
            dst<<" ): {"<<std::endl;
            dst<<std::setw(span*4)<<std::endl;
            block->print(dst,span);
            dst<<" }"<<std::endl;
        }
};

class case_statement : public Node {
    private:
        NodePtr case_value;
        ListPtr body;
    public:
        case_statement(NodePtr _case_value, ListPtr _body)
            :   case_value(_case_value),
                body(_body)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"case ( ";
            case_value->print(dst,span);
            dst<<" ):"<<std::endl;
            dst<<std::setw(span*4)<<std::endl;
            for (int i = (body)->size(); i > 0; i--) {
                (*body)[i-1]->print(dst, span+1);
            }

        }
};

class default_statement : public Node {
    private:
        ListPtr body;
    public:
        default_statement(ListPtr _body)
            : body(_body)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"default :";
            dst<<std::setw(span*4)<<std::endl;
            for (int i = (body)->size(); i > 0; i--) {
                (*body)[i-1]->print(dst, span+1);
            }
        }
};

#endif
