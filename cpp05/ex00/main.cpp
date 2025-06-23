#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Brad", 200); // <- cette ligne va lancer une exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "[150 +] " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("Brad", -200); // <- cette ligne va lancer une exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "[1 -] " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b(NULL, 200); // <- cette ligne va lancer une exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "[NULL Name] " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("Brad", 150); // <- cette ligne va lancer une exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "[OK !] " << e.what() << std::endl;
    }
        try
    {
        Bureaucrat b("Trent", 140);
        std::cout << b << std::endl;
        b += 5;
        std::cout << b << std::endl;
        b -= 10;
        std::cout<< b << std::endl;
        b += 20;
        std::cout << b << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "[OK !] : " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("Trent", 10);
        std::cout << b << std::endl;
        b += 5;
        std::cout << "Après += 5 : " << b << std::endl;
        b -= 10;
        std::cout << "Après -= 10 : " << b << std::endl;
        b += 20;
    }
    catch (const std::exception& e)
    {
        std::cerr << "[OK !] : " << e.what() << std::endl;
    }
    Bureaucrat b("Kevin", 150);
    std::cout << b;
    return 0;
}
