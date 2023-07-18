#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &copyR){ *this = copyR; }
RPN &RPN::operator=(const RPN &copyR){ 
    this->myDeque = copyR.myDeque;
    this->myVector = copyR.myVector;
    return (*this); }
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
}

int RPN::CheckVector(){

    int try_c = 0, catch_c = 0, treshold = 0;

    for(unsigned int i = 0;i<myVector.size();i++){
        if (myVector[i].length() > 1)
            return (0);
        try{
                std::stoi(myVector[i]);
                try_c++;
                treshold++;
        } catch(const std::exception &e){
            catch_c++;
            treshold--;
            if (myVector[i] != "*" && myVector[i] != "/"
                && myVector[i] != "+" && myVector[i] != "-")
                return 0; 
            }
        if (treshold < 1)
            return 0;
    }
    if (try_c-1 != catch_c)
        return 0;
    return 1;
}

void DequeUtils(float result,std::deque<float>& myDeque){
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.push_back(result);
}

void ProccessRPNutils(int op,float result, std::deque<float>& myDeque){
    switch(op){
        case 1:
            result = myDeque[myDeque.size() - 2] + myDeque[myDeque.size() - 1];
            DequeUtils(result,myDeque);
            break;
        case 2:
            result = myDeque[myDeque.size() - 2] - myDeque[myDeque.size() - 1];
            DequeUtils(result,myDeque);
            break;
        case 3:
            result = myDeque[myDeque.size() - 2] * myDeque[myDeque.size() - 1];
            DequeUtils(result,myDeque);
            break;
        case 4:
            result = myDeque[myDeque.size() - 2] / myDeque[myDeque.size() - 1];
            DequeUtils(result,myDeque);
            break;
    }
}

void RPN::ProcessRPN(){
    float result = 0;
    for(unsigned int i =0; i< myVector.size(); i++){
        try{
            myDeque.push_back(std::stoi(myVector[i]));
        } catch (const std::exception &e){
            if (myVector[i] == "+")
                ProccessRPNutils(1,result,myDeque);
            else if (myVector[i] == "-")
                ProccessRPNutils(2,result,myDeque);
            else if (myVector[i] == "*")
                ProccessRPNutils(3,result,myDeque);
            else if (myVector[i] == "/")
                ProccessRPNutils(4,result,myDeque);
        }
    }
    std::cout << myDeque[0] << std::endl;
}