#include "Bureaucrat.hpp"
//Makefile -std=c+98
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
}