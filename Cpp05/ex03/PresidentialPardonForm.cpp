#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("presidential",25,5), target(target)
{ std::cout << "presidential created" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(): AForm("default",25,5)
{ std::cout << "presidential contructor created" << std::endl; }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p): AForm(p), target(p.target)
{ std::cout << "presidential copy consturctor called" << std::endl;}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{ this->AForm::operator=(p); return (*this); }
PresidentialPardonForm::~PresidentialPardonForm()
{ std::cout << "presidential destructor called" << std::endl;}

const std::string &PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->AForm::execute(executor);
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." 
    << std::endl;
}