#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os  << "\033[91m" << b.getName() << "\033[97m" << ", bureaucrat grade " << "\033[93m" << b.getGrade()  << "\033[0m" << std::endl;
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "[Bureaucrat Exception: Grade is too HIGH!]";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "[Bureaucrat Exception: Grade is too LOW!]";
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

Bureaucrat::Bureaucrat()
{
    this->_name = "random name";
    this->_grade = 150;
    std :: cout << "\033[92m" << "default constructor called : " << "\033[0m" << *this << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if(this->getGrade() > 150)
        throw GradeTooLowException();
    else if(this->getGrade() < 0)
        throw GradeTooHighException();
    std :: cout << "\033[92m" << "constructor called : " << "\033[0m" << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) 
{
    std :: cout << "\033[92m" << "copy constructor called : " << "\033[0m" << *this << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[" << "\033[33m" << this->getName() << "\033[0m" << "] left work earlier this time, he was at grade [" << "\033[35m" << this->getGrade() << "\033[0m" "]" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_name = other._name;
    this->_grade = other._grade;
    return *this;
}

void Bureaucrat::increment()
{
    std::cout << "want to increment [" << "\033[33m" << this->getName() << "\033[0m"  << "] : " << "\033[35m"  << this->getGrade() << "\033[0m" << " before increment" << std::endl;
    if(this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrement()
{
    std::cout << "want to decrement [" << "\033[33m" << this->getName() << "\033[0m"  << "] : " << "\033[35m"  << this->getGrade() << "\033[0m" << " before decrement" << std::endl;
    if(this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "\033[96m" << this->getName() << " signed " << form.getName() << "\033[0m" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "\033[96m" << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << "\033[0m" << std::endl;
    }
}


