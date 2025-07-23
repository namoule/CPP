#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void PresidentialPardonForm::setTarget(std::string target)
{
    this->_target = target;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("")
{
    std::cout << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
    std::cout << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
    os  << "\033[91m" << form.getName() << "\033[97m" << ", grade " << "\033[93m" << form.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << form.getGradeSign() << "\033[0m" << " to sign with status : "  << "\033[93m" << form.getStatus() << "\033[0m" << " (0 = non-signed | 1 = signed)" << std::endl;
    return os;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
