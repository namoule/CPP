#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _wpn(NULL), name(name){}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &wpn)
{
    this->_wpn = &wpn;
}

void HumanB::attack() const
{
    if(!_wpn)
        std::cout << name << " attacks with their...with nothing" << std::endl;
    else
        std::cout << name << " attacks with their " << _wpn->getType() << std::endl;
}
