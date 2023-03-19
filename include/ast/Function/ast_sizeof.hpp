#ifndef ast_sizeof_hpp
#define ast_sizeof_hpp

#include "../ast_node.hpp"

#include "../ast_helper.hpp"

class SizeOf : public Node {
    private:
        NodePtr expr;

    public:
        SizeOf(NodePtr _expr)
            : expr(_expr)
        {}
        virtual int getSize(std::map<std::string, std::vector<std::string>> &bindings) const{
            std::string returned_type = expr->getType(bindings);

            if (returned_type == "struct"){
                auto it = bindings.find(expr->getId());
                return std::stoi(it->second.at(2));

            }
            else {
                Helper helper_temp = Helper();
                return helper_temp.type_to_size(returned_type);
            }

        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<" ( ";
            expr->print(dst, span);
            dst<<" )";

        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return bindings.at(getType());
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{
                dst<<"li "<<destReg<<", "<<getSize(bindings)<<std::endl;
        }
};

#endif
