#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;
        void action() const;
};

#endif