#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

    public:
    AForm *makeForm(const std::string &name, const std::string &target);

    Intern();
    Intern(const Intern &i);
    Intern &operator=(const Intern &i);
    ~Intern();

    class InvalidFormNameException: std::exception
    {
        virtual const char * what() const throw()
        {
            return "Invalid Form Name";
        }
    };
};

#endif
