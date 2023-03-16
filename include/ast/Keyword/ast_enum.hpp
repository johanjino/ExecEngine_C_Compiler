#ifndef ast_enum_hpp
#define ast_enum_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Enum_Dec : public Node {
    private:
        NodePtr id;
        NodePtr val;
    public:
        Enum_Dec(NodePtr _id, NodePtr _val)
            :   id(_id),
                val(_val)
        {}

        virtual std::string getId() const override
        { return id->getId(); }

        virtual void print(std::ostream &dst, int span) const override{
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                if (val!=NULL){
                    helper.last_enum = val->getValue(); //This wont work when enum values are expression
                }
                else{
                    helper.last_enum += 1;
                }
                helper.global_enums[id->getId()] = helper.last_enum;


        }

};

class Enum : public Node {
    private:
        ListPtr enums;
    public:
        Enum(ListPtr _enums)
            :   enums(_enums)
        {}

        virtual std::string getId() const override
        { return "ENUM"; }

        virtual void print(std::ostream &dst, int span) const override{
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                helper.last_enum = -1;
                for (int i=0; i<(*enums).size();i++){
                    (*enums)[i]->riscv_asm(dst, helper, destReg, bindings, datatype);
                }
                helper.last_enum = -1;
        }

};




#endif
