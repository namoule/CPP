#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->setGrades(72, 45);
    this->setName("RobotomyRequestForm");
    std::cout << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "copy : " << this->getName() << " " << this->getGradeSign() << " " << this->getGradeExec() << " " << this->getStatus() << std::endl;
}

RobotomyRequestForm RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    this->setGrades(other.getGradeSign(), other.getGradeExec());
    this->setName(other.getName());
    this->setStatus(other.getStatus());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", grade " << "\033[93m" << b.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << b.getGradeSign() << "\033[0m" << " to sign with status : "  << "\033[93m" << b.getStatus() << "\033[0m" <<  " (0 = non-signed | 1 = signed)" << std::endl;
    return os;
}

void RobotomyRequestForm::drillingNoise(std::string target)
{
    std::cout << "****Drilling noises****";
    if(rand() % 2)
        std::cout << target << "\033[92m" << " you have been Robotomized" << "\033[0m" << std::endl;
    else
        std::cout << target << "\033[91m" << " Robotomization failed" << "\033[0m" << std::endl;    
}