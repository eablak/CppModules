#include "Harl.hpp"
#include <iostream>

int find_index(std::string complain)
{
    std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    for(int i = 0; i < 4;i++)
    {
        if (levels[i] == complain)
            return (i);
    }
    return (-1);
}

void handle_complain(std::string complain,Harl harl)
{
    int index = find_index(complain);
    switch(index)
    {
        case 0:
            harl.complain("DEBUG");
            goto c1;
        case 1:
            c1:
            harl.complain("INFO");
            goto c2;
        case 2:
            c2:
            harl.complain("WARNING");
            goto c3;
        case 3:
            c3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    handle_complain(av[1],harl);
}