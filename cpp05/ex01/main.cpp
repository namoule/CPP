#include "Form.hpp"
#include "Bureaucrat.hpp"
int main()
{
    try // try canonical form
    {
        Form a;
        Form b("Loi duplomb", false, 12, 15);
        Form c(b);
        std::cout << c << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[case 0]" << std::endl;
        Form form("Loi duplomb", false, 12, 15);
        Bureaucrat bureaucrat("Steven", 2);
        form.beSigned(bureaucrat);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
    std::cout << "--------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[case 1]" << std::endl;
        Form form("Loi zo", false, 12, 15);
        Bureaucrat bureaucrat("Pivert", 2);
        form.beSigned(bureaucrat); 
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
    std::cout << "--------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[case 2]" << std::endl;
        Form form("Loi duplomb", false, 12, 15);
        Bureaucrat bureaucrat("Steven", 120);
        form.beSigned(bureaucrat); 
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
    std::cout << "--------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[case 3]" << std::endl;
        Form form("Loi constitutionnelle du 8 mars 2024", false, 12, 15);
        Bureaucrat bureaucrat("Marie-Ange", 12);
        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
        std::cout << "--------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[case 3]" << std::endl;
        Form form("loi de règlement budgétaire", false, 12, 15);
        Bureaucrat bureaucrat("Julie", 120);
        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[94m" <<  e.what() << "\033[0m" << '\n';
    }
}