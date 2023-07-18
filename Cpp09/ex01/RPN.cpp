#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &copyR){ *this = copyR; }
RPN &RPN::operator=(const RPN &copyR){ (void) copyR; return (*this); } //!
RPN::~RPN(){}

void RPN::HandleExp(std::string rpn_exp){

    ss.str(rpn_exp);

    std::string str;
    int count = 0;
    while(ss>>str)
        count++;

    ss.clear();
    ss.str(rpn_exp);
    while(ss>>str)
        myVector.push_back(str);

    // for(unsigned int i = 0;i<myVector.size();i++)
    //     std::cout << myVector[i] <<std::endl;
}

int RPN::CheckVector(){
    for(unsigned int i = 0;i<myVector.size();i++){
        if (myVector[i].length() > 1)
            return (0);

        try{
                std::stoi(myVector[i]);
                if (i == myVector.size() - 1)
                    return 0;
        } catch(const std::exception &e){
            if (myVector[i] != "*" && myVector[i] != "/"
                && myVector[i] != "+" && myVector[i] != "-")
                return 0; 
            if (i == 0 || i%2==1)
                return 0;
            }
    }
    return 1;
}

void RPN::ProcessRPN(){

    int result = std::stoi(myVector[0]);
    for(unsigned int i = 1;i < myVector.size();i+=2){
        if (myVector[i+1] == "+")
            result = result + std::stoi(myVector[i]);
        else if (myVector[i+1] == "-")
            result = result - std::stoi(myVector[i]);
        else if (myVector[i+1] == "*")
            result = result * std::stoi(myVector[i]);
        else if (myVector[i+1] == "/")
            result = result / std::stoi(myVector[i]);
        if (i == myVector.size() - 2)
            break;
    }
    std::cout << result << std::endl;
}