#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{

    private:
        std::string _target;
    public: 
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        void setTarget(std::string target);


        void executeAction() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b);

#endif
