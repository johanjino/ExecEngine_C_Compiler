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

        virtual std::string getType(const std::map<std::string, std::vector<std::string>> &bindings = {})const override
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



        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                std::string mem = helper.allocateMemory();
                std::vector<std::string> properties;
                properties.push_back(mem);
                properties.push_back(type->getType());
                bindings[id->getId()] = properties;

                for (int i = 1; i < size->getValue(); i++){
                    std::string mem = helper.allocateMemory();
                }
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
                index(_index),
                value(_value)
        {}

        virtual const char *getOpcode(){return "=";}

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return value; }

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

      virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                if(value==NULL){
                    std::string reg_index = helper.allocateReg(datatype);
                    index->riscv_asm(dst, helper, reg_index, bindings, datatype);

                    std::string reg_min_mem = helper.allocateReg("int");

                    dst<<"li "<<reg_min_mem<<", "<<helper.min_mem<<std::endl;
                    dst<<"mul "<<reg_index<<", "<<reg_index<<", "<<reg_min_mem<<std::endl;
                    dst<<"li "<<reg_min_mem<<", "<<bindings[id->getId()][0]<<std::endl;
                    dst<<"sub "<<reg_index<<", "<<reg_min_mem<<", "<<reg_index<<std::endl;
                    dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                    dst<<"lw "<<destReg<<", "<<"0("<<reg_index<<")"<<std::endl;
                    dst<<"addi "<<reg_min_mem<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_index<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_min_mem);
                    helper.deallocateReg(reg_index);
                }
                else{
                    std::string reg_val = helper.allocateReg(datatype);
                    value->riscv_asm(dst, helper, reg_val, bindings, datatype);

                    std::string reg_index = helper.allocateReg(datatype);
                    index->riscv_asm(dst, helper, reg_index, bindings, datatype);

                    std::string reg_min_mem = helper.allocateReg("int");

                    dst<<"li "<<reg_min_mem<<", "<<helper.min_mem<<std::endl;
                    dst<<"mul "<<reg_index<<", "<<reg_index<<", "<<reg_min_mem<<std::endl;
                    dst<<"li "<<reg_min_mem<<", "<<bindings[id->getId()][0]<<std::endl;
                    dst<<"sub "<<reg_index<<", "<<reg_min_mem<<", "<<reg_index<<std::endl;
                    dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                    dst<<"sw "<<reg_val<<", "<<"0("<<reg_index<<")"<<std::endl;
                    dst<<"addi "<<reg_val<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_min_mem<<", zero, 0"<<std::endl;
                    dst<<"addi "<<reg_index<<", zero, 0"<<std::endl;
                    helper.deallocateReg(reg_val);
                    helper.deallocateReg(reg_min_mem);
                    helper.deallocateReg(reg_index);
                }
        }

};







#endif
