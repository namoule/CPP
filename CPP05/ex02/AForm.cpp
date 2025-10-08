#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", AForm grade " << "\033[93m" << b.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << b.getGradeSign() << "\033[0m" << " to sign with status : " << b.getStatus() <<  " (0 = non-signed | 1 = signed )" << std::endl;
    return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "/*AForm Exception: Grade is too HIGH!*/";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "/*AForm Exception: Grade is too LOW!*/";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "/*AForm Exception: Form is not Signed!*/";
}

std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getGradeExec() const
{
    return this->_gToexec;
}

int AForm::getGradeSign() const
{
    return this->_gToSign;
}

bool AForm::getStatus() const
{
    return this->_signed;
}


AForm::AForm()
{
    this->_name = "random name Aform";
    this->_signed = false;
    this->_gToSign = 150;
    this->_gToexec = 150;
}

AForm::AForm(std::string name, bool signd,  int gradeSign, int gradeExec) : _name(name), _signed(signd), _gToSign(gradeSign), _gToexec(gradeExec)
{
    std :: cout << "\033[92m" << "constructor called : " << "\033[0m" << *this << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gToSign(other._gToSign), _gToexec(other._gToexec)
{
    std :: cout << "\033[92m" << "copy constructor called : " << "\033[0m" << *this << std::endl;
}

AForm::~AForm()
{
    std::cout << "[" << "\033[33m" << this->getName() << "\033[0m" << "] has been put in the paper shredder, grade needed were [" << "\033[35m" << this->getGradeSign() << "\033[0m" "] to sign and " << "[" << "\033[35m" << this->getGradeExec() << "\033[0m" << "] , and had status " << this->getStatus() <<  std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    this->_name = other._name;
    this->_gToexec = other._gToexec;
    this->_gToSign = other._gToSign;
    return *this;
}

void AForm::beSigned(Bureaucrat &writer)
{
    if(this->_gToSign < writer.getGrade())
    {
        throw GradeTooLowException();
    }
    this->_signed = true;
}


void AForm::setGrades(int valSign, int valExec)
{
    this->_gToexec = valExec;
    this->_gToSign = valSign;
}

void AForm::setName(std::string newName)
{
    this->_name = newName;
}

void AForm::setStatus(bool status)
{
    this->_signed = status;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    this->executeAction();
}
