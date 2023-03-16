//This class is used to create all helper functions needed to be used during genereating RISC-V code
#ifndef ast_helper_hpp
#define ast_helper_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <memory>

#include "../ast.hpp"


//NEED TO FIX FUNCTION CALLS. ALL REGISTERS NEED TO BACKUP TO MEMORY.


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

        int Regs_floats[32] = {
            1,                      //f0            zero        Zero
            0,                      //f1            ra          Return address
            0,                      //f2            sp          Stack pointer
            0,                      //f3            gp          Global pointer
            0,                      //f4            tp          Thread pointer
            0,0,0,                  //f5 - f7       t0 - t2     Temporary registers
            1,1,                    //f8 - f9       s0 - s1     Callee-saved registers
            1,1,1,1,1,1,1,1,        //f10 - f17     a0 - a7     Argument registers
            0,0,0,0,0,0,0,0,0,0,    //f18 - f27     s2 - s11    Callee-saved registers
            0,0,0,0                 //f28 - f31     t3 - t6     Temporary registers
        };

        std::string function_end;


    public:
        virtual ~Helper(){
        }

        //Constructs
        Helper(){}


        // loop end and start
        std::vector<std::string> loop_end;
        std::vector<std::string> loop_update;
        std::vector<std::string> loop_start;

        void new_loop(std::string new_loop_start, std::string new_loop_end, std::string new_loop_update = "None"){
            loop_start.push_back(new_loop_start);
            loop_update.push_back(new_loop_update);
            loop_end.push_back(new_loop_end);
        }
        void exit_loop(){
            if (!loop_start.empty()){
                loop_start.pop_back();
                loop_update.pop_back();
                loop_end.pop_back();
            }
            else{
                std::cerr << "Tried to break or continue in a scope of no loops" << std::endl;
                exit(1);
            }
        }
        std::string get_loop_labels(std::string where){
            if (where == "Start"){
                return loop_start.back();
            }
            else if (where == "End"){
                return loop_end.back();
            }
            else if (where == "Update"){
                return loop_update.back();
            }
            else{
                return "invalid location to jump";
            }
        }


        //Creates Labels for function jumps
        std::string createLabel(std::string name){
            static int label_count = 0;
            label_count+=1;
            return "_"+name+"_"+std::to_string(label_count);
        }


        std::string getfunctionEnd(){
            return function_end;
        }



        //Switch Handling
        std::vector<std::string> switch_reg;
        std::vector<std::string> switch_label;
        std::vector<std::string> switch_status;


        //Enum Handling
        int last_enum = -1;
        std::map<std::string, int> global_enums;


        /*
        -----------------------------MEMORY MANAGEMENT-------------------------------
        */


        //Scopes
        int current_scope = 0;
        std::vector<std::map<std::string, std::vector<std::string>>> Scopes;
        std::vector<int> mem_scope;

        //Properties
        std::map<std::string, std::vector<std::string>> bindings;

        //Memory allocation for scalability
        int default_mem_allocation  = 128;
        int last_mem_allocated = 128;
        int min_mem = 4;



        //occupy using register
        void useReg(int i){
            Regs[i] = 1;
        }
        void useReg_float(int i){
            Regs_floats[i] = 1;
        }


        //deallocate register
        void deallocateReg(std::string &reg){
            if (reg[0] == 'f'){
                Regs_floats[std::stoi(reg.erase(0,1))] = 0;
            }
            else{
                Regs[std::stoi(reg.erase(0,1))] = 0;
            }
        }


        //need to implement memory clean when out of scope


        //find register to use
        std::string allocateReg(std::string datatype){
            if (datatype == "float" || datatype == "double" || datatype == "long double"){
                for(int i=0; i<32; i++){
                    if (Regs_floats[i] == 0){
                        useReg_float(i);
                        return "f" + std::to_string(i);
                    }
                }
            }
            else{
                for(int i=0; i<32; i++){
                    if (Regs[i] == 0){
                        useReg(i);
                        return "x" + std::to_string(i);
                    }
                }
            }
            std::cerr << "Register Block!" << std::endl;    //need to implement better memory management
            exit(1);
        }


        //find memory offset to use
        std::string allocateMemory(){
            if (last_mem_allocated == 0){
                std::cerr << "StackOverFlow!" << std::endl;    //need to implement better memory management
                exit(1);
            }
            last_mem_allocated = last_mem_allocated - min_mem;
            return std::to_string(last_mem_allocated);
        }







        // To save all temporary register in current scope
        //(use this function carefully. Very stupid way to solve a problem. Huge memory wasteage)
        void save_regs(std::ostream &dst){
            for(int i=0; i<7; i++){
                dst<<"sw t"<<i<<", "<<allocateMemory()<<"(sp)"<<std::endl;
            }
        }


        // To load all registers from current scope
        //(use this function carefully. Very stupid way to solve a problem. Huge memory wasteage)
        void load_regs(std::ostream &dst){
            for(int i=6; i>-1; i--){
                    dst<<"lw t"<<i<<", "<<last_mem_allocated<<"(sp)"<<std::endl;
                    last_mem_allocated = last_mem_allocated + min_mem;
                }
        }


        //New Memory Scope and New Bindings
        void newScope(std::ostream &dst, bool override_return = true){
            std::map<std::string, std::vector<std::string>> bindings_new;
            Scopes.push_back(bindings);
            mem_scope.push_back(last_mem_allocated);
            current_scope += 1;
            bindings = bindings_new;
            last_mem_allocated = default_mem_allocation;
            if (override_return){
                function_end = createLabel("function_end");
            }


            //sp allocate
            dst<<"addi sp, sp, "<<"-"<<default_mem_allocation<<std::endl;   //we assume that the tree has stored the value of ra

        }


        //Exit current scope and Delete Bindings
        void exitScope(std::ostream &dst, bool override_return = true){
            if (current_scope > 0){
                current_scope = current_scope - 1;
                bindings = Scopes[current_scope];
                last_mem_allocated = mem_scope[current_scope];
                Scopes.pop_back();
                mem_scope.pop_back();

                //sp reset
                if (override_return){
                    dst<<function_end<<":"<<std::endl;
                    function_end = "Wrong Function End";    //for debugging
                }
                dst<<"addi sp, sp, "<<default_mem_allocation<<std::endl;


            }
            else if (current_scope == 0){
                //this is probably called when main ends

            }
            else{
                std::cerr << "Exiting beyond base scope!" << std::endl;    //need to implement better memory management
                exit(1);
            }
        }



};





#endif
