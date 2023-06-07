#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("esra",130);
    ShrubberyCreationForm s("sh");

    std::cout << b.getGrade() << std::endl;
    b.signForm(s);
    // s.beSigned(b);

    std::cout << s.get_sign_grade() << std::endl;
    // std::cout << s.get_execute_grade() << std::endl;
    std::cout << s.get_is_signed() << std::endl;
    
    std::cout << std::endl;
    std::cout << b.getGrade() << std::endl;
    std::cout << s.get_execute_grade() << std::endl;

    b.executeForm(s);

    std::cout << std::endl;
    RobotomyRequesForm r("robot");
    Bureaucrat b2("new_b",30);
    std::cout << b2.getGrade() << std::endl;
    std::cout << r.get_execute_grade() << std::endl;
    // r.beSigned(b2);
    r.set_sign(true);
    r.execute(b2);

    std::cout << std::endl;
    PresidentialPardonForm p("p_target");
    Bureaucrat b3("pb",4);
    std::cout << p.get_sign_grade() << std::endl;
    std::cout << p.get_execute_grade() << std::endl;
    // p.beSigned(b3);
    p.set_sign(true);
    p.execute(b3);


    std::cout << std::endl;
}