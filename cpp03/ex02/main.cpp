#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main(void)
{
    std::string str = "FragTrap";
    FragTrap a(str);
    str = "ScavTrap";
    std::cout << std::endl;
    ScavTrap b(str);
    std::cout << std::endl;
    a.highFiveGuys();
    std::cout << std::endl;
    a.highFiveGuys();
    std::cout << std::endl;
    b.guardGate();
    std::cout << std::endl;
    b.guardGate();
    std::cout << std::endl;
    return(1);
}