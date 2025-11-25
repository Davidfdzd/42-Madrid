#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    this->action();
}

void ShrubberyCreationForm::action(void) const{
    std::ofstream out((getTarget() + "_shrubbery").c_str());
    if (!out)
    {
        std::cerr << "Error: Could not create shrubbery file" << std::endl;
        return;
    }
    out << "       _-_" << std::endl;
    out << "    /~~   ~~\\" << std::endl;
    out << " /~~         ~~\\" << std::endl;
    out << "{               }" << std::endl;
    out << " \\  _-     -_  /" << std::endl;
    out << "   ~  \\\\ //  ~" << std::endl;
    out << "_- -   | | _- _" << std::endl;
    out << "  _ -  | |   -_" << std::endl;
    out << "      // \\\\" << std::endl;
    out.close();
}