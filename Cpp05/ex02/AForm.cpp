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
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::set_sign(bool sign)
{
    this->is_signed = sign;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (this->get_is_signed() == false)
        throw AForm::FormNotSignedException();
    else
        std::cout << executor.getName() << "'s form signed" << std::endl;
    if (executor.getGrade() > this->get_execute_grade())
        throw AForm::GradeTooLowException();
    else
        std::cout << executor.getName() << "'s grade("
        << executor.getGrade() << ") is enough"<< std::endl;
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
    return o << "Form name: " << f.getName()
    << " sign grade " << f.get_sign_grade()
    << " execute grade" << f.get_execute_grade()
    << " is signed " << f.get_is_signed() << std::endl;
}