#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public: 
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &other);
        RobotomyRequestForm operator=(RobotomyRequestForm &other);
        void drillingNoise(std::string target);

};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b);

#endif