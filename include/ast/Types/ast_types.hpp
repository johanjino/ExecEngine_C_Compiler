#ifndef ast_types_hpp
#define ast_types_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


enum _Types{
    _int,
    _unsigned_int,
    _long,
    _unsigned_long,
	_char,
    _unsigned_char,
    _signed_char,
	_short,
    _unsigned_short,
	_float,
	_double,
    _long_double,
	_void
};


class Type : public Node {

    private:
        _Types type;

    public:
        Type(const _Types &_type)
            : type(_type)
        {}

        virtual std::string getType() const override{
            switch (type){
                case (_int):
                    return "int";
                case (_unsigned_int):
                    return "unsigned int";
                case (_long):
                    return "long";
                case (_unsigned_long):
                    return "unsigned long";
                case (_char):
                    return "char";
                case (_unsigned_char):
                    return "unsigned char";
                case (_signed_char):
                    return "signed char";
                case (_short):
                    return "short";
                case (_unsigned_short):
                    return "unsigned short";
                case (_float):
                    return "float";
                case (_double):
                    return "double";
                case (_long_double):
                    return "long double";
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
