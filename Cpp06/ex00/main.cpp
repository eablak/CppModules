#include "ScalarConverter.hpp"

void check_unknown(ScalarConverter *s)
{
    std::cout << s->getString() << " is not convertable!" << std::endl;
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
    std::cout << "type " << s.getType() << std::endl;
}