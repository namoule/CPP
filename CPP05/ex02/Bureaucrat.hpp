#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;

    public:
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

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        void signAForm(AForm &Aform);
        void executeForm(AForm const &form) const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
