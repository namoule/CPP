#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", Form grade " << "\033[93m" << b.getGradeExec() << "\033[0m" << " to exec, and " << "\033[93m" << b.getGradeSign() << "\033[0m" << " to sign with status : " << b.getStatus() <<  " (0 = non-signed | 1 = signed )" << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "/*Form Exception: Grade is too HIGH!*/";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "/*Form Exception: Grade is too LOW!*/";
}

std::string Form::getName() const
{
    return this->_name;
}

int Form::getGradeExec() const
{
    return this->_gToexec;
}

int Form::getGradeSign() const
{
    return this->_gToSign;
}

bool Form::getStatus() const
{
    return this->_signed;
}


Form::Form()
{
    this->_name = "random name form";
    this->_signed = false;
    this->_gToSign = 150;
    this->_gToexec = 150;

    std :: cout << "\033[92m" << "default constructor called : " << "\033[0m" << *this << std::endl;
}

Form::Form(std::string name, bool signd,  int gradeSign, int gradeExec) : _name(name), _signed(signd), _gToSign(gradeSign), _gToexec(gradeExec)
{
    std :: cout << "\033[92m" << "constructor called : " << "\033[0m" << *this << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gToSign(other._gToSign), _gToexec(other._gToexec)
{
    std :: cout << "\033[92m" << "copy constructor called : " << "\033[0m" << *this << std::endl;
}

Form::~Form()
{
    std::cout << "[" << "\033[33m" << this->getName() << "\033[0m" << "] has been put in the paper shredder, grade needed were [" << "\033[35m" << this->getGradeSign() << "\033[0m" "] to sign and " << "[" << "\033[35m" << this->getGradeSign() << "\033[0m" << "] , and had status " << this->getStatus() <<  std::endl;
}

Form& Form::operator=(const Form& other)
{
    this->_name = other._name;
    this->_gToexec = other._gToexec;
    this->_gToSign = other._gToSign;
    return *this;
}

void Form::beSigned(Bureaucrat &writer)
{
    if(this->_gToSign < writer.getGrade())
    {
        throw GradeTooLowException();
    }
    this->_signed = true;
}
