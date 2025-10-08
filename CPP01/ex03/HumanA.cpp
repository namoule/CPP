#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wpn) : _wpn(wpn), name(name) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << _wpn.getType() << std::endl;
}
