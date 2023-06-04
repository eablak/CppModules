#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    const std::string target;

    public:
    const std::string &getTarget() const;

    ShrubberyCreationForm(const std::string &target);
    
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &r);
    ShrubberyCreationForm &operator = (const ShrubberyCreationForm &r);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};

#endif
