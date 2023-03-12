#ifndef ast_strings_chars_hpp
#define ast_strings_chars_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Strings : public Node {
private:
    std::string sentence;
public:
    Strings(std::string _sentence)
        : sentence(_sentence)
    {}
    virtual std::string getId() const override
    { return sentence; }

    virtual void print(std::ostream &dst, int span) const override
    {
        dst<<"\"";
        dst<<sentence;
        dst<<"\"";
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
