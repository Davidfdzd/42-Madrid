#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
        std::srand(std::time(NULL));
    }

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    //this->action();
}
void RobotomyRequestForm::action(void) const{
    std::cout << "Bzzzzzzzzzzzz... drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << this->getTarget() << "." << std::endl;
}