#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequesForm::RobotomyRequesForm(const std::string &target): AForm("robotmy",72,45), target(target)
{ std::cout << "robotmy created" << std::endl;}

RobotomyRequesForm::RobotomyRequesForm(): AForm("default",72,45)
{std::cout << "robotomy default created" << std::endl;}
RobotomyRequesForm::RobotomyRequesForm(const RobotomyRequesForm &r): AForm(r), target(r.target)
{ std::cout << "robotmy copy consturctor called" << std::endl;}
RobotomyRequesForm &RobotomyRequesForm::operator=(const RobotomyRequesForm &r)
{this->AForm::operator=(r); return (*this);}
RobotomyRequesForm::~RobotomyRequesForm()
{ std::cout << "robotmy destructor called" << std::endl;}

const std::string &RobotomyRequesForm::getTarget() const
{
    return this->target;
}

void RobotomyRequesForm::execute(Bureaucrat const &executor) const
{
    this->AForm::execute(executor);
    std::cout << "xxxxx noises" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}