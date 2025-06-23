#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

    class Bureaucrat
    {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(const char* givenName, int grade);
        ~Bureaucrat();
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
        Bureaucrat& operator+=(int n);
        Bureaucrat& operator-=(int n);
        std::string getName() const;
        int getGrade() const;
    };

#endif
