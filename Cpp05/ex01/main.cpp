#include "Bureaucrat.hpp"
//zsh iot check
int main()
{
    Bureaucrat b("b1",42);
    Form f("form",10,120);

    std::cout << f.getName() << std::endl;
    std::cout << f.get_sign_grade() << std::endl;
    std::cout << f.get_execute_grade() << std::endl;
    std::cout << f.get_is_signed() << std::endl;

    f.beSigned(b);
    std::cout << f.get_is_signed() << std::endl;

    b.signForm(f);

    f.set_sign(0);
    std::cout << f.get_is_signed() << std::endl;

    b.signForm(f);

    Form f2("ff",100,120);
    b.signForm(f2);
}