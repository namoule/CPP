#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "i use getGrade() and getName() to print messages in every constructors/destructors" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    Bureaucrat a; // fc 
    Bureaucrat b("steve", 15); // fc
    Bureaucrat c(b); // fc
    std::cout << b; // fc
    std::cout << "--------------------------------------------------" << std::endl;

    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 0]" << "\033[0m" << std::endl;
    //     Bureaucrat a;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m" << e.what() << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 1]" << "\033[0m" << std::endl;
    //     Bureaucrat b("Ashtyn", 50);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 2]" << "\033[0m" << std::endl;
    //     Bureaucrat b("Beth", 50);
    //     Bureaucrat c(b);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 3]" << "\033[0m" << std::endl;
    //     Bureaucrat d("Cinder", 160);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << "\n";
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 4]" << "\033[0m" << std::endl;
    //     Bureaucrat e("Daphné", -50);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << "\n";
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 5]" << "\033[0m" << std::endl;
    //     Bureaucrat a("Eve", 75);
    //     a.decrement();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 6]" << "\033[0m" << std::endl;
    //     Bureaucrat a("Freya", 75);
    //     a.increment();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 7]" << "\033[0m" << std::endl;
    //     Bureaucrat a("Glynis", 150);
    //     a.decrement();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
    // std::cout << "--------------------------------------------------" << std::endl;
    // try
    // {
    //     std::cout << "\033[93m" << "[case 8]" << "\033[0m" << std::endl;
    //     Bureaucrat a("Hannah", 1);
    //     a.increment();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "\033[36m"<< e.what() << "\033[0m" << '\n';
    // }
}