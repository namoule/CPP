#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
    std::cout << "intern have been created" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern() 
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other; 
    return *this;
}


AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string names[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            AForm* form = NULL;
            switch (i)
            {
                case 0: form = new PresidentialPardonForm(target); break;
                case 1: form = new RobotomyRequestForm(target); break;
                case 2: form = new ShrubberyCreationForm(target); break;
            }
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cerr << "Intern couldn't find form named '" << formName << "'" << std::endl;
    return NULL;
}


