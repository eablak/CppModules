#include "Bureaucrat.hpp"
//zsh iot check
int main()
{
    Bureaucrat bureaucrat("esra",10);
    std::cout << bureaucrat.getName() << std::endl;
    std::cout << bureaucrat << std::endl;
    Bureaucrat b("toomuch",1);
    // b.incrementGrade();
    Bureaucrat b2("b",45);
    b2.incrementGrade();
    b2.decrementGrade();
    b2.decrementGrade();
    std::cout << b2.getGrade() << std::endl;
    std::cout << b2;


    Bureaucrat b_ex("dsf",0);
}