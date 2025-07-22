#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    this->setGrades(25, 5);
    this->setName("PresidentialPardonForm");
    std::cout << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[" << this->getName() << "] have been put to paper shredder" << std::endl; 
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "copy : " << this->getName() << " " << this->getGradeSign() << " " << this->getGradeExec() << " " << this->getStatus() << std::endl;
}

PresidentialPardonForm PresidentialPardonForm::operator=(PresidentialPardonForm &other)
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


void PresidentialPardonForm::presidentialPardon(std::string target)
{
    (void)target;
}