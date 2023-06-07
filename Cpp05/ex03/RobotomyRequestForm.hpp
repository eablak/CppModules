#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequesForm: public AForm
{
    const std::string target;

    public:
    const std::string &getTarget() const;

    RobotomyRequesForm(const std::string &target);

    RobotomyRequesForm();
    RobotomyRequesForm(const RobotomyRequesForm &r);
    RobotomyRequesForm &operator=(const RobotomyRequesForm &r);
    ~RobotomyRequesForm();

    void execute(Bureaucrat const & executor) const;
};

#endif