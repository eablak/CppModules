#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name,int grade): name(name),grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(){ std::cout << "created" << std::endl; return ;}
Bureaucrat::Bureaucrat(const Bureaucrat &copyB): name(copyB.getName()), grade(copyB.grade)
{std::cout << "Bureaucrat is copied from " << copyB.getName() << std::endl;}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copyB){
  this->grade = copyB.grade; 
  return (*this);  }
Bureaucrat::~Bureaucrat(){std::cout << "destructed" << std::endl;}

const std::string &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &str)
{
    return out << "Bureaucrat name: " << str.getName() 
    << ", grade: " << str.getGrade() << std::endl;
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.get_is_signed() == true)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
            << " beacuse is already signed" << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);
    }
    catch(AForm::GradeTooLowException &exception)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
            << " beacuse it's too low" << std::endl;
        return;
    }
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    try{ form.execute(*this); }
    catch(std::exception &e)
    { std::cout << "Something's going wrong!" << std::endl; }
    std::cout << this->getName() << " executed " 
        << form.getName() << std::endl;
}