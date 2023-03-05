#ifndef ast_types_hpp
#define ast_types_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


enum _Types{
    _int,
    _long,
	_char,
	_short,
	_signed,
	_unsigned,
	_float,
	_double,
	_void
};


class Type : public Node {

    private:
        _Types type;

    public:
        Type(const _Types &_type)
            : type(_type)
        {}

        const std::string getType() const{
            switch (type){
                case (_int):
                    return "int";
                case (_long):
                    return "long";
                case (_char):
                    return "char";
                case (_short):
                    return "short";
                case (_signed):
                    return "signed";
                case (_unsigned):
                    return "unsigned";
                case (_float):
                    return "float";
                case (_double):
                    return "double";
                case (_void):
                    return "void";
                default:
                    return "unknown data type";
            }
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<getType()<<" ";
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return bindings.at(getType());
        }
};

#endif
