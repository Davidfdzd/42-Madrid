#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// Custom Constructor
	Bureaucrat(const std::string &name, int grade);

	// Getters
	std::string getName() const;
	int getGrade() const;

	// Grade management
	void incrementGrade();
	void decrementGrade();

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif