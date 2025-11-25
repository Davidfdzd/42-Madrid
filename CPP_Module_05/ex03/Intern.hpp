#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        static AForm* createShrubbery(const std::string &target);
        static AForm* createRobotomy(const std::string &target);
        static AForm* createPresidential(const std::string &target);
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target);
};

#endif