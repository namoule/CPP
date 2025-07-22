#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void PresidentialPardonForm::setTarget(std::string target)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm()
{
    this->setGrades(25, 5);
    this->setName("PresidentialPardonForm");
    std::cout << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->setGrades(25, 5);
    this->setName("PresidentialPardonForm");
    this->setTarget(target);
    std::cout << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    this->setGrades(other.getGradeSign(), other.getGradeExec());
    this->setName(other.getName());
    this->setStatus(other.getStatus());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", grade " << "\033[93m" << b.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << b.getGradeSign() << "\033[0m" << " to sign with status : "  << "\033[93m" << b.getStatus() << "\033[0m" <<  " (0 = non-signed | 1 = signed)" << std::endl;
    return os;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();

    std::cout << "\033[94m" << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n" << "\033[0m" << std::endl;
}
