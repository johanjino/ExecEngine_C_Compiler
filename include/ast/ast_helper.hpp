//This class is used to create all helper functions needed to be used during genereating RISC-V code
#ifndef ast_helper_hpp
#define ast_helper_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>


#include "ast_helper.hpp"



class Helper {
    public:
        virtual ~Helper(){
        }

        std::string createLabel(std::string name){
            static int label_count = 0;
            return "_"+name+"_"+std::to_string(label_count);
        }
};


#endif
