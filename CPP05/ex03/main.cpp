#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someIntern;

    Bureaucrat boss("Boss", 1);
    Bureaucrat junior("Junior", 150);

    AForm* form1 = someIntern.makeForm("PresidentialPardon", "Arthur");
    AForm* form2 = someIntern.makeForm("RobotomyRequest", "Marvin");
    AForm* form3 = someIntern.makeForm("ShrubberyCreation", "Home");
    AForm* form4 = someIntern.makeForm("UnknownForm", "Nobody");

    std::cout << "\n--- Forms created ---\n";
    if (form1)
        std::cout << *form1 << std::endl;
    if (form2)
        std::cout << *form2 << std::endl;
    if (form3)
        std::cout << *form3 << std::endl;
    if (!form4)
        std::cout << "form4 is NULL (unknown form request)" << std::endl;

    std::cout << "\n--- Signing attempts ---\n";
    if (form1) junior.signAForm(*form1);
    if (form1) boss.signAForm(*form1);

    if (form2) junior.signAForm(*form2);
    if (form2) boss.signAForm(*form2);

    if (form3) junior.signAForm(*form3);
    if (form3) boss.signAForm(*form3);

    std::cout << "\n--- Execution attempts ---\n";
    if (form1) junior.executeForm(*form1);
    if (form1) boss.executeForm(*form1);

    if (form2) junior.executeForm(*form2);
    if (form2) boss.executeForm(*form2);

    if (form3) junior.executeForm(*form3);
    if (form3) boss.executeForm(*form3);

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
