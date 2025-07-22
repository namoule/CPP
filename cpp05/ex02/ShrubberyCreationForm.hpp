#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &other);
        ShrubberyCreationForm operator=(ShrubberyCreationForm &other);
        void createFile(std::string target);
        void printTree(std::ostringstream &oss);
        std::string renameFile(std::string target);
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b);

#endif