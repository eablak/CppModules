#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("esra",10);
    std::cout << bureaucrat;
    Bureaucrat b("toomuch",2);
    Bureaucrat b2("b",45);
    try {
        b.incrementGrade();
        std::cout << b2.getGrade() << std::endl;
        b2.incrementGrade();
        std::cout << b2.getGrade() << std::endl;
        b2.decrementGrade();
        std::cout << b2.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getGrade() << std::endl;
    } catch(std::exception &e){
        std::cout << e.what();
    }
}