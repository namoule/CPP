#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string _name;
        bool    _signed;
        int     _gToSign;
        int     _gToexec;
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
        Form();
        Form(std::string name, bool signd,  int gradeSign, int gradeExec);
        Form(const Form&);
        ~Form();
        Form &operator=(const Form&);
        std::string getName() const;
        int getGradeExec() const; 
        int getGradeSign() const;
        bool getStatus() const;
        void beSigned(Bureaucrat &writer);
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif