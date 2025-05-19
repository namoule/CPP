#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << "Adresse de la variable str: " << &str << std::endl;
    std::cout << "Adresse contenue dans stringPTR: " << stringPTR << std::endl;
    std::cout << "Adresse contenue dans stringREF: " << &stringREF << std::endl;
    
    std::cout << "Valeur de la variable str: " << str << std::endl;
    std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;
    
    return 0;
}
