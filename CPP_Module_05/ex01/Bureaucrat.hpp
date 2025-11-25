#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat(const std::string &name, int grade);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw(); //what devuelve un mensaje de error en forma de const char*
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif