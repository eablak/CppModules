#include "Intern.hpp"

Intern::Intern() { std::cout << "intern created" << std::endl;}
Intern::Intern(const Intern &i)
{ *this=i; std::cout << "intern copy consturctor called" << std::endl; }
Intern &Intern::operator=(const Intern &i)
{ (void) i; return (*this);}
Intern::~Intern(){ std::cout << "intern destructor called" << std::endl; }

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string formNames[3] = {"presidential pardon", 
        "robotomy request", "shrubbery creation"};
    int i;
    for(i = 0; i< 3 && formNames[i] != name; i++){}
    AForm *ret = NULL;
    switch(i){
        case 0:
        {
            ret = new PresidentialPardonForm(target);
            break;
        }
        case 1:
        {
            ret = new RobotomyRequesForm(target);
            break;
        }
        case 2:
        {
            ret = new ShrubberyCreationForm(target);
            break;
        }
        default:
            throw InvalidFormNameException();
    }
    std::cout << "Intern creates " << name << std::endl;
    return ret;
}