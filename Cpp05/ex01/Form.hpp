#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Form
{
    const std::string name;
    bool sign;
    int grade_sign;
    int grade_execute;

    public:
    Form();
    Form(const Form &copyF);
    Form &operator=(const Form &copyF);
    ~Form();

    void getName();

    class GradeTooHighException: std::exception
    {
        virtual const char *what() const throw
        {
            return "Grade Too High Exception";
        }
    }

    class GradeTooLowException: std::exception
    {
        virtual const char *what() const throw
        {
            return "Grade Too Low Exception";
        }
    }
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif