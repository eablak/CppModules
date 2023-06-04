#include "AForm.hpp"

AForm::AForm(std::string name, int sign_grade, int execute_grade) 
    : name(name), sign_grade(sign_grade), execute_grade(execute_grade)
{ this->is_signed = false; return ;}

AForm::AForm(): name("Aform"), is_signed(0), sign_grade(1), execute_grade(1)
{std::cout << "Aform created" << std::endl;}
AForm::AForm(const AForm &Aform): name(Aform.getName()), is_signed(Aform.get_is_signed()),
    sign_grade(Aform.get_sign_grade()), execute_grade(Aform.get_execute_grade())
{std::cout << "Aform is copied from " << Aform.getName() << std::endl;}
AForm& AForm::operator=(const AForm &copy)
{ this->is_signed = copy.is_signed; return *this;}
AForm::~AForm() {std::cout << "Aform destructed" << std::endl;}

const std::string &AForm::getName() const
{
    return this->name;
}

int AForm::get_sign_grade() const
{
    return this->sign_grade;    
}

int AForm::get_execute_grade() const
{
    return this->execute_grade;
}

bool AForm::get_is_signed() const
{
    return this->is_signed;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() < this->sign_grade)
        throw GradeTooLowException();
    this->is_signed = true;
}

void AForm::set_sign(bool sign)
{
    this->is_signed = sign;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (this->get_is_signed() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->get_sign_grade())
        throw AForm::GradeTooLowException();
}