#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->setGrades(145, 137);
    this->setName("ShrubberyCreationForm");
    std::cout << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "copy : " << this->getName() << " " << this->getGradeSign() << " " << this->getGradeExec() << " " << this->getStatus() << std::endl;
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
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


    
void ShrubberyCreationForm::printTree(std::ostringstream &oss)
{
    oss << "a tree";
}


void ShrubberyCreationForm::createFile(std::string target)
{
    std::ostringstream oss;
    this->printTree(oss);
    std::ofstream outFile(target.append("_shrubbery").c_str());
    try
    {
        outFile.is_open();
        outFile << oss.str();
        outFile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}