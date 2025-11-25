#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string	_name;
    bool				_isSigned;
    const int			_gradeToSign;
    const int			_gradeToExecute;
public:
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    std::string getName() const;
    bool getIsSigned() const;
    int getToSign() const;
    int getToExecute() const;

    class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

    void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif