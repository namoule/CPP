#include "ScavTrap.hpp"

int main(void)
{
    std::string str = "ScavTrap";
    ScavTrap a(str);
    a.guardGate();
    a.guardGate();
    a.attack("a cute dog");
    a.takeDamage(10);
    a.beRepaired(10);
    a.beRepaired(10);
    return(1);
}