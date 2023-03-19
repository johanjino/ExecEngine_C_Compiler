#ifndef ast_struct_hpp
#define ast_struct_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class Struct_Dec : public Node {
    private:
        NodePtr name;
        ListPtr properties;
    public:
        Struct_Dec(NodePtr _name, ListPtr _prop)
            :   name(_name),
                properties(_prop)
        {}

        virtual std::string getId() const override
        { return name->getId(); }

        virtual void print(std::ostream &dst, int span) const override{
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::map<std::string, std::string> property;
                for(int i=0; i<(*properties).size(); i++){
                    std::string type = (*properties)[i]->getType();
                    std::string id = (*properties)[i]->getId();
                    property[id] = type;
                }
                
                helper.structs_created[name->getId()] = property;
        }

};


class Struct_Init : public Node {
    private:
        NodePtr name;
        NodePtr variable;
    public:
        Struct_Init(NodePtr _name, NodePtr _var)
            :   name(_name),
                variable(_var)
        {}

        virtual std::string getId() const override
        { return name->getId(); }

        virtual void print(std::ostream &dst, int span) const override{
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                int max_element_size = 0;
                int new_element_size = 0;
                int element_count = 0;

                std::vector<std::string> temp;
                temp.push_back("0");
                temp.push_back("struct");

                for (auto const &x : helper.structs_created[name->getId()]) {
                    std::string mem = helper.allocateMemory();
                    std::vector<std::string> properties;
                    properties.push_back(mem);
                    properties.push_back(x.second);

                    new_element_size = helper.type_to_size(x.second);
                    if (new_element_size > max_element_size){
                        max_element_size = new_element_size;
                    }
                    bindings[variable->getId() + "." + x.first] = properties;

                    element_count ++;
                }
                temp.push_back(std::to_string(max_element_size * element_count));
                bindings[variable->getId()] = temp; //to make sure variable exist in binding, not completely neccessary
                //iterate through each property
        }

};



#endif
