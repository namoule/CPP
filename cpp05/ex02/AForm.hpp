#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
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

        class FormNotSignedException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

        AForm();
        AForm(std::string name, bool signd,  int gradeSign, int gradeExec);
        AForm(const AForm&);
        ~AForm();

        AForm &operator=(const AForm&);

        std::string getName() const;
        int getGradeExec() const; 
        int getGradeSign() const;
        bool getStatus() const;
        
        void setName(std::string newName);
        void setGrades(int valSign, int valExec);
        void setStatus(bool status);

        void beSigned(Bureaucrat &writer);
        bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif