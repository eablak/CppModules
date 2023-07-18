#ifndef RPN_HPP
#define RPN_HPP
#include <queue>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

class RPN{
    
    std::queue<std::string>myQueue;
    std::vector<std::string>myVector;

    public:
    std::stringstream ss;
    std::string *arr;

    RPN();
    RPN(const RPN &copyR);
    RPN &operator=(const RPN &copyR);
    ~RPN();

    void HandleExp(std::string av);
    int CheckVector();
    void ProcessRPN();
};

#endif