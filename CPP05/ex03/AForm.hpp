#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        std::string _name;
        bool _signed;
        int _gToSign;
        int _gToexec;
        std::string _target;
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
        AForm(std::string name, bool signd, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        virtual ~AForm();

        AForm& operator=(const AForm& other);

        std::string getName() const;
        int getGradeExec() const;
        int getGradeSign() const;
        bool getStatus() const;

        void setName(std::string newName);
        void setGrades(int valSign, int valExec);
        void setStatus(bool status);

        void beSigned(Bureaucrat &writer);

        virtual void executeAction() const = 0;

        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
