#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b("esra",20);
    ShrubberyCreationForm s("shrubbery");

    // s.beSigned(b);
    // s.execute(b);

    b.executeForm(s);
}