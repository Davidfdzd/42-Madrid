#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
    bool				_isSigned;
    const int			_gradeToSign;
    const int			_gradeToExecute;
    const std::string   _target;
public:
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
    std::string getName() const;
    bool getIsSigned() const;
    int getToSign() const;
    int getToExecute() const;
    std::string getTarget() const;

    class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

    class GradeNotSignedException : public std::exception {
    public:
        const char *what() const throw();
    };

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(const Bureaucrat &executor) const;
    virtual void action() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif