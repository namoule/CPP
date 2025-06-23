#include "Bureaucrat.hpp"

const char* GradeTooHighException::what() const throw()
{
    return "Grade too high, must be between 1 and 150.";
}

const char* GradeTooLowException::what() const throw()
{
    return "Grade too low, must be between 1 and 150.";
}

Bureaucrat::Bureaucrat(const char* givenName, int grade)
    : _name(givenName ? std::string(givenName) : throw std::invalid_argument("Name is empty"))
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "[Bureaucrat] Hi {" << this->getName() << "} welcome at rank {" << this->getGrade() << "}" << std::endl;
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "[~Bureaucrat] " << this->_name << " left work, see you tomorrow." << std::endl;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os <<  b.getName() << ", bureaucrat grade " << b.getGrade() <<std::endl;
    return os;
}

Bureaucrat& Bureaucrat::operator+=(int n)
{
    if (_grade - n < 1)
        throw GradeTooHighException();

    _grade -= n;
    return *this;
}

Bureaucrat& Bureaucrat::operator-=(int n)
{
    if (_grade + n > 150)
        throw GradeTooLowException();

    _grade += n;
    return *this;
}
