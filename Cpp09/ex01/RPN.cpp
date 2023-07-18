#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &copyR){ *this = copyR; }
RPN &RPN::operator=(const RPN &copyR){ (void) copyR; return (*this); } //!
RPN::~RPN(){}

void RPN::ExpCount(std::string rpn_exp){
    
    std::stringstream ss(rpn_exp);
    std::string str;
    this->count = 0;

    while(ss>>str)
        count++;
}

// void RPN::FillRPN(){
//     this->arr[count];
    
// }