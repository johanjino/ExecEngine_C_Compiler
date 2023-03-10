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
        virtual int getSize() const{
            std::string returned_type = expr->getType();

            if (returned_type == "int"){
                return 4;
            }
            else if(returned_type == "long"){
                return 8;
            }
            else if(returned_type == "char"){
                return 1;
            }

            else if(returned_type == "short"){
                return 2;
            }

            else if(returned_type == "signed"){
                return 4;
            }

            else if(returned_type == "unsigned"){
                return 4;
            }

            else if(returned_type == "float"){
                return 4;
            }

            else if(returned_type == "double"){
                return 4;
            }

            else if(returned_type == "void"){
                return 1;
            }
            else {
                std::cerr<<"Invalid Data Type Size Read Attempt!"<<std::endl;
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
};

#endif
