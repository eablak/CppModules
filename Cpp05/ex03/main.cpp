#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* rrf2;
    // AForm* rrf3;

    try{

            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            rrf2 = someRandomIntern.makeForm("presidential pardon","ppardoon");
            // rrf3 = someRandomIntern.makeForm("shrubbery","shrubbery");

            Bureaucrat b("a",3);
            rrf->beSigned(b);
            rrf->execute(b);

            std::cout << std::endl << rrf2->get_is_signed() << std::endl;
            rrf2->set_sign(true);
            std::cout << rrf2->get_execute_grade() << std::endl;
            rrf2->execute(b);
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    // delete rrf;
}