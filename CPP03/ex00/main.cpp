#include "ClapTrap.hpp"

int main(void)
{
   ClapTrap a("number one");
   a.takeDamage(5);
   a.beRepaired(3);
    int i = 0;
    while(i < 10)
    {
        a.attack("a huge victim");
        i++;
    }
    i = 0;
    while(i < 5)
    {
        std::cout << std::endl;
        i++;
    }
    ClapTrap b("number two");
    b.takeDamage(5);
    b.beRepaired(3);
    b.takeDamage(9);
    std::cout << std::endl;
    std::cout << std::endl;
    return(1);
}