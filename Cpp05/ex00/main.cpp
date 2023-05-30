#include "Bureaucrat.hpp"
//Makefile -std=c+98
int main()
{
    Bureaucrat bureaucrat("esra",10);
    std::cout << bureaucrat.getName() << std::endl;
    std::cout << bureaucrat << std::endl;
    Bureaucrat b("toomuch",1);
    b.incrementGrade();
}