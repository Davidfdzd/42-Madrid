#include "Form.hpp"

// ---------------- Canonical form ---------------- //
Form::Form() : _name("Unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    *this = other;
}

Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

// ---------------- Custom constructor ---------------- //
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    this->_isSigned = false;
}

// ---------------- Getters ---------------- //
std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getToSign() const {
    return this->_gradeToSign;
}

int Form::getToExecute() const {
    return this->_gradeToExecute;
}

// ---------------- Exceptions ---------------- //
const char *Form::GradeTooHighException::what() const throw() {
    return "Form Exception: Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form Exception: Grade too low!";
}

// ---------------- Member functions ---------------- //
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

// ---------------- Overload of << operator ---------------- //
std::ostream &operator<<(std::ostream &out, const Form &f) {
    out  << f.getName() << ", Signed:" << f.getIsSigned()
        << ", grade required to execute: " << f.getToExecute() 
        << ", grade required to signed: " << f.getToSign();
    return out;
}