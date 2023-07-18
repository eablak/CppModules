#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2){
        std::cout << "Error: Expression" << std::endl;
        exit(1);
    }
    
    RPN rpn;
    rpn.HandleExp(av[1]);
    if (rpn.CheckVector())
        rpn.ProcessRPN();
    else
        std::cout << "Error" << std::endl;
}