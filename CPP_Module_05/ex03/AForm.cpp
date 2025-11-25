#include "AForm.hpp"

// ---------------- Canonical form ---------------- //
AForm::AForm() : _name("Unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150), _target("None") {}

AForm::AForm(const AForm &other)
    : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {
    *this = other;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

// ---------------- Custom constructor ---------------- //
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

// ---------------- Getters ---------------- //
std::string AForm::getName() const { return this->_name; }
bool AForm::getIsSigned() const { return this->_isSigned; }
int AForm::getToSign() const { return this->_gradeToSign; }
int AForm::getToExecute() const { return this->_gradeToExecute; }
std::string AForm::getTarget() const { return this->_target; }

// ---------------- Exceptions ---------------- //
const char *AForm::GradeTooHighException::what() const throw() { return "Form Exception: Grade too high!"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Form Exception: Grade too low!"; }
const char *AForm::GradeNotSignedException::what() const throw() { return "Form Exception: The form is not signed!"; }

// ---------------- Member functions ---------------- //
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_isSigned)
        throw GradeNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    this->action();
}

// ---------------- Overload of << operator ---------------- //
std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << "Form " << f.getName()
        << " | Signed: " << std::boolalpha << f.getIsSigned()
        << " | Grade to sign: " << f.getToSign()
        << " | Grade to execute: " << f.getToExecute()
        << " | Target: " << f.getTarget();
    return out;
}