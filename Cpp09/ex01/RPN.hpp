#ifndef RPN_HPP
#define RPN_HPP
#include <queue>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

class RPN{
    
    std::deque<float>myDeque;
    std::vector<std::string>myVector;

    public:
    std::stringstream ss;

    RPN();
    RPN(const RPN &copyR);
    RPN &operator=(const RPN &copyR);
    ~RPN();

    void HandleExp(std::string av);
    int CheckVector();
    void ProcessRPN();
};

#endif