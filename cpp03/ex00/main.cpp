#include "ClapTrap.hpp"

int main(void)
{
   ClapTrap a("number one");
   a.takeDamage(5);
   a.beRepaired(3);
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");
   a.attack("a huge victim");

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    ClapTrap b("number two");
    b.takeDamage(5);
    b.beRepaired(3);
    b.takeDamage(9);
    
    std::cout << std::endl;
    std::cout << std::endl;
    return(1);
}