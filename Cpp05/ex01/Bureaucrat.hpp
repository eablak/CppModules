#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    const std::string name;
    int grade;

    public:
    Bureaucrat(std::string name,int grade);

    Bureaucrat();
    Bureaucrat(const Bureaucrat &copyB);
    Bureaucrat &operator = (const Bureaucrat &copyB);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade();
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too High";
        }
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too Low";
        }
    };

    void signForm(Form &form);
};

std::ostream& operator<<(std::ostream &out,Bureaucrat &str);

#endif