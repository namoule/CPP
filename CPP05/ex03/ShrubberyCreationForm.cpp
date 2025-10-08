#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void ShrubberyCreationForm::setTarget(std::string target)
{
    this->_target = target;
}

std::string ShrubberyCreationForm::getTarget()
{
    return this->_target;
}


ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->setGrades(145, 137);
    this->setName("ShrubberyCreationForm");
    this->setTarget("Target");
    std::cout << *this << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->setGrades(145, 137);
    this->setName("ShrubberyCreationForm");
    this->setTarget(target);
    std::cout << *this << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "copy : " << this->getName() << " " << this->getGradeSign() << " " << this->getGradeExec() << " " << this->getStatus() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    this->setGrades(other.getGradeSign(), other.getGradeExec());
    this->setName(other.getName());
    this->setStatus(other.getStatus());
    return *this;
}


std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", grade " << "\033[93m" << b.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << b.getGradeSign() << "\033[0m" << " to sign with status : "  << "\033[93m" << b.getStatus() << "\033[0m" <<  " (0 = non-signed | 1 = signed)" << std::endl;
    return os;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ostringstream oss;
    oss << "       _-_       \n"
           "    /~~   ~~\\   \n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\ //  ~ \n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\n";

    std::ofstream outFile((this->getName() + "_shrubbery").c_str());
    outFile << oss.str();
    outFile.close();
}
