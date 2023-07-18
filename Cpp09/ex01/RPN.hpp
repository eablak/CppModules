#ifndef RPN_HPP
#define RPN_HPP
#include <queue>
#include <iostream>
#include <sstream>

class RPN{
    
    std::queue<std::string>myQueue;

    public:

    unsigned int count;
    std::string *arr;

    RPN();
    RPN(const RPN &copyR);
    RPN &operator=(const RPN &copyR);
    ~RPN();

    void ExpCount(std::string av);
    void FillRPN();
};

#endif