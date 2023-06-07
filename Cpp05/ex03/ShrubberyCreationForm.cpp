#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
    AForm("Shrubbery",145,137), target(target)
    {std::cout << "shrubbery created" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default",145,137)
{std::cout << "shrubbery default constructor created" << std::endl;}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &r):
    AForm(r), target(r.target)
{std::cout << "shrubbery copy constructor called" << std::endl;}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &r)
{this->AForm::operator=(r); return *this;}
ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "shrubbery destructor called" << std::endl;}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->AForm::execute(executor);
    std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
    ofs << "       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\"
	<< std::endl;
    ofs.close();
}