#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("b1",42);
    Form f("form",50,120);

    try{
        std::cout << f.getName() << std::endl;
        std::cout << f.get_sign_grade() << std::endl;
        std::cout << f.get_execute_grade() << std::endl;
        std::cout << f.get_is_signed() << std::endl;

        f.beSigned(b);
        std::cout << f.get_is_signed() << std::endl;

        b.signForm(f);

        f.set_sign(30);
        Form f2("ff",100,120);
        b.signForm(f2);
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}