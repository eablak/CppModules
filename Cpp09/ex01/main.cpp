#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2){
        std::cout << "Error: Expression" << std::endl;
        exit(1);
    }
    
    RPN rpn;
    rpn.ExpCount(av[1]);
    // rpn.FillRPN();
}