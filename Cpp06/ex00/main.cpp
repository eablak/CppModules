#include "ScalarConverter.hpp"
#include <iomanip>

void result(ScalarConverter *s, int type)
{
    float number = atof(&(s->getString())[0]);
    std::cout << "number " << number << std::endl;
    std::cout << "char: ";
    if (type == 0)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" <<  static_cast<char>(number) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(number) << std::endl;
    std::cout << std::fixed << std::scientific << std::setprecision(3) << "float: " << static_cast<float>(number) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void _convert(ScalarConverter *s)
{
    switch(s->getType())
    {
        case 0:
            result(s, 0);
            break;
        case 1:
            result(s, 1);
            break;
        case 2:
            result(s, 2);
            break;
        case 3:
            result(s, 3);
            break;
    }
}

void check_unknown(ScalarConverter *s)
{
    std::cout << "'" << s->getString() << "' is not convertable!" << std::endl;
    exit(1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    ScalarConverter s;
    s.setString(av[1]);
    s.findType(&s);
    if (s.getType() == 4)
        check_unknown(&s);
    _convert(&s);
}