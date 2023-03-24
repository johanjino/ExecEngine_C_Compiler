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

                    // Temporary fix to pass the strings/escaped.c test case
                    // and at the same time pass other string tests and
                    // allign with our array storing and accessing methodology
                    if (str[i]=='\\'){
                        dst<<"li "<<reg_val<<", '\\"<<str[i]<<"'"<<std::endl;
                    }
                    else if(str[i]=='\n'){
                        dst<<"li "<<reg_val<<", '\n"<<str[i]<<"'"<<std::endl;
                    }
                    else if(str[i]=='\t'){
                        dst<<"li "<<reg_val<<", '\t"<<str[i]<<"'"<<std::endl;
                    }
                    else if(str[i]=='\''){
                        dst<<"li "<<reg_val<<", '\'"<<str[i]<<"'"<<std::endl;
                    }
                    else if(str[i]=='\"'){
                        dst<<"li "<<reg_val<<", '\""<<str[i]<<"'"<<std::endl;
                    }
                    else if(str[i]=='\?'){
                        dst<<"li "<<reg_val<<", '\?"<<str[i]<<"'"<<std::endl;
                    }
                    else{
                        dst<<"li "<<reg_val<<", '"<<str[i]<<"'"<<std::endl;
                    }

                    dst<<"li "<<reg_index<<", "<<i<<std::endl;
                    dst<<"mul "<<reg_index<<", "<<reg_index<<", "<<reg_min_mem<<std::endl;
                    dst<<"li "<<reg_min_mem<<", "<<bindings[id->getId()][0]<<std::endl;
                    dst<<"sub "<<reg_index<<", "<<reg_min_mem<<", "<<reg_index<<std::endl;
                    dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                    dst<<"sw "<<reg_val<<", "<<"0("<<reg_index<<")"<<std::endl;

                }
                dst<<"addi "<<reg_val<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_index<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_min_mem<<", zero, 0"<<std::endl;

                helper.deallocateReg(reg_val);
                helper.deallocateReg(reg_min_mem);
                helper.deallocateReg(reg_index);

        }
};

class Strings_Output : public Node {
private:
    std::string sentence;
public:
    Strings_Output(std::string _sentence)
            : sentence(_sentence)
    {}

    virtual void print(std::ostream &dst, int span) const override
    {
            dst<<sentence;
            dst<<std::endl;
    }

  //	STRING_LITERAL 				{$$ = new Strings_Output(*$1);}
        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                // std::string header_mem = helper.allocateMemory();

                // std::string mem = helper.allocateMemory();

                // std::string str = sentence.substr(1, sentence.length() - 2);

                // for (int i = 1; i < str.size(); i++){
                //     helper.allocateMemory();
                // }

                // std::string reg_val = helper.allocateReg(datatype);
                // std::string reg_index = helper.allocateReg(datatype);
                // std::string reg_min_mem = helper.allocateReg("int");

                // for (int i = 0; i < str.size(); i++){
                //     dst<<"li "<<reg_min_mem<<", "<<helper.min_mem<<std::endl;
                //     dst<<"li "<<reg_val<<", '"<<str[i]<<"'"<<std::endl;
                //     dst<<"li "<<reg_index<<", "<<i<<std::endl;
                //     dst<<"mul "<<reg_index<<", "<<reg_index<<", "<<reg_min_mem<<std::endl;
                //     dst<<"li "<<reg_min_mem<<", "<<mem<<std::endl;
                //     dst<<"sub "<<reg_index<<", "<<reg_min_mem<<", "<<reg_index<<std::endl;
                //     dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                //     dst<<"sw "<<reg_val<<", "<<"0("<<reg_index<<")"<<std::endl;
                // }

                // dst<<"sw zero,"<<helper.allocateMemory()<<"(sp)"<<std::endl;


                // dst<<"li "<<reg_index<<", "<<mem<<std::endl;
                // dst<<"add "<<reg_index<<", "<<reg_index<<", sp"<<std::endl;
                // dst<<"li "<<reg_val<<", "<<header_mem<<std::endl;
                // dst<<"add "<<reg_val<<", "<<reg_val<<", sp"<<std::endl;
                // dst<<"sw "<<reg_index<<", 0("<<reg_val<<")"<<std::endl;

                // dst<<"add "<<destReg<<", zero,"<<reg_val<<std::endl;

                // dst<<"addi "<<reg_val<<", zero, 0"<<std::endl;
                // dst<<"addi "<<reg_index<<", zero, 0"<<std::endl;
                // dst<<"addi "<<reg_min_mem<<", zero, 0"<<std::endl;

                // helper.deallocateReg(reg_val);
                // helper.deallocateReg(reg_min_mem);
                // helper.deallocateReg(reg_index);

    //After spending 5 hours on trying to figure out why our elegent piece of code is not working,
    //we realise that its not us, but GCC! :(
    //Now, to allign with how GCC deals with strings, we are forced to follow this ruthless new method
    //which his highness GCC and her majesty GodBolt uses :(

                std::vector<std::string> new_header;
                std::string header_label = helper.createLabel(sentence.substr(1, sentence.length()-2));

                new_header.push_back(header_label);
                new_header.push_back(".string "+ sentence);

                helper.add_header(new_header);

                std::string reg = helper.allocateReg("int");

                dst<<"lui "<<reg<<", %hi("<<header_label<<")"<<std::endl;
                dst<<"addi "<<destReg<<", "<<reg<<", %lo("<<header_label<<")"<<std::endl;
                dst<<"addi "<<reg<<", zero, 0"<<std::endl;

                helper.deallocateReg(reg);
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
