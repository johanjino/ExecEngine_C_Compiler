#ifndef ast_switch_case_hpp
#define ast_switch_case_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"
#include "../ast_listnode.hpp"


class switch_statement : public Node {
    private:
        NodePtr case_expr;
        ListPtr block;
    public:
        switch_statement(NodePtr _case_expr, ListPtr _block)
            :   case_expr(_case_expr),
                block(_block)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"switch ( ";
            case_expr->print(dst,span);
            dst<<" ): {"<<std::endl;
            dst<<std::setw(span*4)<<std::endl;
            for (int i = (block)->size(); i > 0; i--) {
                (*block)[i-1]->print(dst, span+1);
            }
            dst<<" }"<<std::endl;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const override{

            //create labels
            std::string condition_reg = helper.allocateReg(datatype);
            std::string end_switch = helper.createLabel("end_switch");
            helper.loop_end.push_back(end_switch);
            helper.switch_reg.push_back(condition_reg);
            helper.switch_label.push_back("NULL");
            helper.switch_status.push_back("START");

            //evalute conditon
            case_expr->riscv_asm(dst, helper, condition_reg, bindings);

            for (int i = (block)->size(); i > 0; i--) {
                if (i == (block)->size()){
                    helper.switch_status.pop_back();
                    helper.switch_status.push_back("START");
                }
                else if (i==1){
                    helper.switch_status.pop_back();
                    helper.switch_status.push_back("END");
                }
                else{
                    helper.switch_status.pop_back();
                    helper.switch_status.push_back("NULL");
                }
                (*block)[i-1]->riscv_asm(dst, helper, destReg, bindings);
            }

            //end switch
            dst<<end_switch<<":"<<std::endl;
            helper.loop_end.pop_back();
            helper.switch_reg.pop_back();
            helper.switch_label.pop_back();
            helper.switch_status.pop_back();

            //deallocate
            dst<<"addi "<<condition_reg<<", zero, 0"<<std::endl;
            helper.deallocateReg(condition_reg);

        }
};

class case_statement : public Node {
    private:
        NodePtr case_value;
        NodePtr body;
    public:
        case_statement(NodePtr _case_value, NodePtr _body)
            :   case_value(_case_value),
                body(_body)
        {}
        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"case ( ";
            case_value->print(dst,span);
            dst<<" ):"<<std::endl;
            dst<<std::setw(span*4)<<std::endl;
            body->print(dst,span+1);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const override{

                //Case end label
                std::string case_end = helper.createLabel("case_end");

                //Calculate value
                std::string reg_value = helper.allocateReg(datatype);
                case_value->riscv_asm(dst, helper, reg_value, bindings);

                dst<<"sub "<<reg_value<<", "<<helper.switch_reg.back()<<", "<<reg_value<<std::endl;
                dst<<"bne "<<reg_value<<", zero, "<<case_end<<std::endl;

                if (helper.switch_status.back() != "START"){
                    dst<<helper.switch_label.back()<<":"<<std::endl;
                }

                body->riscv_asm(dst, helper, destReg, bindings, datatype);

                if (helper.switch_status.back() !="END"){
                    std::string switch_label = helper.createLabel("switch_label");
                    helper.switch_label.pop_back();
                    helper.switch_label.push_back(switch_label);
                    dst<<"beq zero, zero, "<<switch_label<<std::endl;
                }

                dst<<case_end<<":"<<std::endl;
                dst<<"addi "<<reg_value<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_value);
        }

};

class default_statement : public Node {
    private:
        NodePtr body;
    public:
        default_statement(NodePtr _body)
            : body(_body)
        {}

        virtual std::string getClass() const{
            return "Default_Switch";
        }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"default :";
            dst<<std::setw(span*4)<<std::endl;
            body->print(dst, span+1);
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None") const override{

                dst<<helper.switch_label.back()<<":"<<std::endl;
                body->riscv_asm(dst, helper, destReg, bindings, datatype);
                dst<<"beq zero, zero, "<<helper.get_loop_labels("End")<<std::endl;
        }
};

#endif
