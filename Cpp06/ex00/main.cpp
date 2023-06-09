#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    // std::string str = av[1];
    // std::cout << str << std::endl;

    char *str = av[1];
    std::cout << "girilen değer " << str << std::endl;
    ScalarConverter s;
    s.findType(str);
    std::cout << "type " << s.getType();
}