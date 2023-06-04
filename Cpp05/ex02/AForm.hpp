#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int execute_grade;

    public:
    AForm(std::string name, int sign_grade, int execute_grade);

    AForm();
    AForm(const AForm &copyF);
    AForm &operator=(const AForm &copyF);
    ~AForm();

    const std::string &getName() const;
    int get_sign_grade() const;
    int get_execute_grade() const;
    bool get_is_signed() const;

    class GradeTooHighException: std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too High Exception";
        }
    };

    class GradeTooLowException: std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too Low Exception";
        }
    };

    void beSigned(Bureaucrat &bureaucrat);
    void set_sign(bool sign);

    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif