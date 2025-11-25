#include "Bureaucrat.hpp"

// ---------------- Canonical form ---------------- //

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	//std::cout << "Bureaucrat " << this->_name << " destroyed." << std::endl;
}

// ---------------- Custom constructor ---------------- //

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
	    throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
	    throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
} //importante porque se construye fuera de limite de grado ya

// ---------------- Getters ---------------- //

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

// ---------------- Grade management ---------------- //

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

// ---------------- Exceptions ---------------- //

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

// ---------------- Operator overload ---------------- //

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} 
	catch (const std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}