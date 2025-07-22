#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>



class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &other);
        PresidentialPardonForm operator=(PresidentialPardonForm &other);
        void presidentialPardon(std::string target);
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b);


#endif