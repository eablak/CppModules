#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int execute_grade;

    public:
    Form(std::string name, int sign_grade, int execute_grade);

    Form();
    Form(const Form &copyF);
    Form &operator=(const Form &copyF);
    ~Form();

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
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif