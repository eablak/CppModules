#include "ScalarConverter.hpp"

void result(ScalarConverter *s, int type)
{
    float number = atof(&(s->getString())[0]);
    if (type == 0 || ((number < 32 || number >= 127) && type != 0))
        std::cout << "char: Non displayable" << std::endl;
    else {
        if (number <= 0 || number > 255 || std::isnan(number))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl; }
    if (number > INT_MAX || number < INT_MIN || std::isnan(number))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << convert_int(s) << std::endl;
    if (std::isinf(convert_float(s)))
        std::cout << "float: inf" << std::endl;
    else {
        std::cout << "float: " << convert_float(s); 
        if (convert_int(s) == convert_float(s))
            std::cout << ".0";
        std::cout << "f" << std::endl; }
    // if (std::isinf(convert_double(s)))
    //     std::cout << "double: inf" << std::endl;
    // else {
        std::cout << "double: " << convert_double(s);
        if (convert_int(s) == convert_double(s))
            std::cout << ".0";
        std::cout << std::endl; //}
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

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    ScalarConverter s;
    ScalarConverter s1;
    s.setString(av[1]);
    s.findType(&s);
    s1 = s;
    if (s1.getType() == 4)
        std::cout << "'" << s1.getString() << "' is not convertable!" << std::endl;
    else
        _convert(&s1);
}