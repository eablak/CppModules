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

int Bureaucrat::getGrade()
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