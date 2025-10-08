#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:
        
    public:
        class notActualFormException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formName, std::string target);
};


#endif