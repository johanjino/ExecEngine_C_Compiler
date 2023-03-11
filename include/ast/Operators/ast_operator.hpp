#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

#include "../ast_node.hpp"


class Operator : public Node{

    protected:
        NodePtr left;
        NodePtr right;
        Helper helper = Helper();

        Operator(NodePtr _left, NodePtr _right)
            : left(_left)
            , right(_right)
        {}
    public:
        virtual ~Operator(){
            delete left;
            delete right;
        }

        virtual std::string getId() const{
            return "Operator";
        }

        virtual const char *getOpcode() const =0;

        NodePtr getLeft() const
        { return left; }

        NodePtr getRight() const
        { return right; }


        virtual std::string getPreferredDatatype(std::string str1, std::string str2) const {
            std::string preferredStr;

            // Define the global precedence order of datatypes here
            std::string precedenceOrder[] = {"long double", "double", "float", "long", "unsigned long", "int", "unsigned int",
                                        "short", "unsigned short", "signed char", "char", "unsigned char"};
            int numStrings = sizeof(precedenceOrder) / sizeof(std::string);

            int index1 = -1;
            int index2 = -1;
            // Find the index of the first datatype in the precedence order array
            for (int i = 0; i < numStrings; i++) {
                if (precedenceOrder[i] == str1) {
                    index1 = i;
                    break;
                }
            }
            // Find the index of the second datatype in the precedence order array
            for (int i = 0; i < numStrings; i++) {
                if (precedenceOrder[i] == str2) {
                    index2 = i;
                    break;
                }
            }
            // Determine the preferred datatype based on the precedence order
            if (index1 >= 0 && (index2 < 0 || index1 < index2)) {
                preferredStr = str1;
            }
            else if (index2 >= 0 && (index1 < 0 || index2 < index1)) {
                preferredStr = str2;
            }
            else {
                // If both strings have the same index in the precedence order array or neither string is in the array, return str1 by default
                    preferredStr = str1;
            }
            return preferredStr;
        }

        virtual std::string getType() const override{
            std::string left_type = left->getType();
            std::string right_type = right->getType();
            return getPreferredDatatype(left_type,right_type);
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<"( ";
            left->print(dst, span);
            dst<<" ";
            dst<<getOpcode();
            dst<<" ";
            right->print(dst, span);
            dst<<" )";
        }
};

#endif
