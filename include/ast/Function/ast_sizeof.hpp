#ifndef ast_sizeof_hpp
#define ast_sizeof_hpp

#include "../ast_node.hpp"

class SizeOf : public Node {
    private:
        NodePtr expr;
    public:
        SizeOf(NodePtr _expr)
            : expr(_expr)
        {}
        virtual int getSize(std::map<std::string, std::vector<std::string>> &bindings) const{
            std::string returned_type = expr->getType(bindings);

            if (returned_type == "int" || returned_type == "unsigned int"){
                return 4;
            }
            else if(returned_type == "long" || returned_type == "unsigned long"){
                return 8;
            }
            else if(returned_type == "char" || returned_type == "unsigned char" || returned_type == "signed char"){
                return 1;
            }

            else if(returned_type == "short" || returned_type == "unsigned short"){
                return 2;
            }

            else if(returned_type == "signed" || returned_type == "unsigned"){
                return 4;
            }

            else if(returned_type == "float"){
                return 4;
            }

            else if(returned_type == "double"){
                return 8;
            }

            else if(returned_type == "long double"){
                return 10;
            }

            else if(returned_type == "void"){
                return 1;
            }
            else {
                std::cerr<<returned_type<<": Invalid Data Type Size Read Attempt!"<<std::endl;

                exit(1);
                return 0;
            }


        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"sizeof ( ";
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
