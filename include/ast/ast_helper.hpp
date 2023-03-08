//This class is used to create all helper functions needed to be used during genereating RISC-V code
#ifndef ast_helper_hpp
#define ast_helper_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

#include "../ast.hpp"




class Helper {
    protected:
        int Regs[32] = {
            1,                      //x0            zero        Zero
            1,                      //x1            ra          Return address
            1,                      //x2            sp          Stack pointer
            1,                      //x3            gp          Global pointer
            1,                      //x4            tp          Thread pointer
            0,0,0,                  //x5 - x7       t0 - t2     Temporary registers
            1,1,                    //x8 - x9       s0 - s1     Callee-saved registers
            1,1,1,1,1,1,1,1,        //x10 - x17     a0 - a7     Argument registers
            1,1,1,1,1,1,1,1,1,1,    //x18 - x27     s2 - s11    Callee-saved registers
            0,0,0,0                 //x28 - x31     t3 - t6     Temporary registers
        };

    public:
        virtual ~Helper(){
        }

        //Properties
        std::map<std::string, std::string> bindings;


        //Constructs
        Helper(){}



        //Creates Labels for function jumps
        std::string createLabel(std::string name){
            static int label_count = 0;
            label_count+=1;
            return "_"+name+"_"+std::to_string(label_count);
        }





        /*
        -----------------------------MEMORY MANAGEMENT-------------------------------
        */



        //occupy using register
        void useReg(int i){
            Regs[i] = 1;
        }


        //deallocate register
        void deallocateReg(int i){
            Regs[i] = 0;
        }


        //need to implement memory clean when out of scope


        //find memory to use
        std::string allocateReg(){
            for(int i=0; i<32; i++){
                if (Regs[i] == 0){
                    useReg(i);
                    return "x" + std::to_string(i);
                }
            }
            std::cerr << "Register Block!" << std::endl;    //need to implement better memory management
            exit(1);
        }


};





#endif
