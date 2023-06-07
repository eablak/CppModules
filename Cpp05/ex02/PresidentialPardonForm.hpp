#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    const std::string target;

    public:
    const std::string &getTarget() const;

    PresidentialPardonForm(const std::string &target);

    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &p);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};

#endif