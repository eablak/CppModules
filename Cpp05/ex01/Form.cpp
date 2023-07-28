#include "Form.hpp"

Form::Form(std::string name, int sign_grade, int execute_grade) 
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{ this->is_signed = false; return ;}

Form::Form(): name("form"), is_signed(0), sign_grade(1), execute_grade(1)
{std::cout << "form created" << std::endl;}
Form::Form(const Form &form): name(form.getName()), is_signed(form.get_is_signed()),
    sign_grade(form.get_sign_grade()), execute_grade(form.get_execute_grade())
{std::cout << "form is copied from " << form.getName() << std::endl;}
Form& Form::operator=(const Form &copy)
{ this->is_signed = copy.is_signed; return *this;}
Form::~Form() {std::cout << "form destructed" << std::endl;}

const std::string &Form::getName() const
{
    return this->name;
}

int Form::get_sign_grade() const
{
    return this->sign_grade;    
}

int Form::get_execute_grade() const
{
    return this->execute_grade;
}

bool Form::get_is_signed() const
{
    return this->is_signed;
}

void Form::beSigned(Bureaucrat &b)
{
    if (get_sign_grade() < b.getGrade())
        throw GradeTooLowException();
    this->is_signed = true;
}

void Form::set_sign(bool sign)
{
    this->is_signed = sign;
}