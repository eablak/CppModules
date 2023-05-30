#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name,int grade): name(name),grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(){ return ;}
Bureaucrat::Bureaucrat(const Bureaucrat &copyB): name(copyB.getName()), grade(copyB.grade){}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copyB){
  *this = copyB; return (*this);  }
Bureaucrat::~Bureaucrat(){}

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