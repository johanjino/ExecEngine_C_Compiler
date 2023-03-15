#ifndef ast_strings_chars_hpp
#define ast_strings_chars_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Strings : public Node {
private:
    NodePtr type;
    NodePtr id;
    std::string sentence;
public:
    Strings(NodePtr _type, NodePtr _id, std::string _sentence)
            :   type(_type),
                id(_id),
                sentence(_sentence)
    {}
    virtual std::string getType(const std::map<std::string, std::vector<std::string>> &bindings = {})const override
    { return (type!=NULL) ? type->getType() : "NULL"; }

    std::string getId() const override
    { return id->getId(); }

    virtual void print(std::ostream &dst, int span) const override
    {
            dst<<std::setw(span*4);
            type->print(dst,span);
            dst<<"*";
            id->print(dst, span);
            dst<<"=";
            dst<<sentence;
            dst<<std::endl;
    }

  //DATA_TYPES '*' IDENTIFIER '=' STRING_LITERAL {$$ = new Strings($1,(new Variable(*$3)), *$5);}
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

                std::string str = sentence.substr(1, sentence.length() - 2);

                for (int i = 1; i < str.size(); i++){
                    std::string mem = helper.allocateMemory();
                }

                std::string reg_val = helper.allocateReg(datatype);
                std::string reg_index = helper.allocateReg(datatype);
                std::string reg_min_mem = helper.allocateReg("int");

                for (int i = 0; i < str.size(); i++){
                    dst<<"li "<<reg_min_mem<<", "<<helper.min_mem<<std::endl;
                    dst<<"li "<<reg_val<<", '"<<str[i]<<"'"<<std::endl;
                    dst<<"li "<<reg_index<<", "<<i<<std::endl;
                    dst<<"mul "<<reg_index<<", "<<reg_index<<", "<<reg_min_mem<<std::endl;
                    dst<<"li "<<reg_min_mem<<", "<<bindings[id->getId()][0]<<std::endl;
                    dst<<"sub "<<reg_index<<", "<<reg_min_mem<<", "<<reg_index<<std::endl;
                    dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                    dst<<"sw "<<reg_val<<", "<<"0("<<reg_index<<")"<<std::endl;

                }

                helper.deallocateReg(reg_val);
                helper.deallocateReg(reg_min_mem);
                helper.deallocateReg(reg_index);
        }
};

class Chars : public Node {
private:
    std::string letter;
public:
    Chars(std::string _letter)
        : letter(_letter)
    {}
    virtual std::string getId() const override
    { return letter; }

    virtual void print(std::ostream &dst, int span) const override
    {
        dst<<letter;
    }
    virtual void riscv_asm(std::ostream &dst,
        Helper &helper,
        std::string destReg,
        std::map<std::string, std::vector<std::string>> &bindings,
        std::string datatype = "None")const override{
         dst<<"li "<<destReg<<", "<<letter<<std::endl;
    }

};





#endif
