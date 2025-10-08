#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(name)
{
    this_name = _name;
    this->attackDamage = 20;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->_gateKeepMode = false;
    std::cout << "default constructor ScavTrap called and the given attacks damage are : " << this->attackDamage << ", " << this->hitPoints << " hits points, " << this->energyPoints << " energy points." << std::endl;
}

ScavTrap::~ScavTrap()
{
        std::cout << "ScavTrap died with :" << this->hitPoints << " hitPoints, " << this->attackDamage << " attack damage, " << this->energyPoints << " energy points." << std::endl;
}

void ScavTrap::guardGate()
{
    if(this->_gateKeepMode == false)
    {
        std::cout << "Guardian mode activated !" << std::endl;
        this->_gateKeepMode = true;
    }
    else
    {
        std::cout << "Guardian mode disabled." << std::endl;
        this->_gateKeepMode = false;
    }
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << _name << " use his special attack on " << target << " ! and cause : " << this->attackDamage << " damage points" << std::endl;
    this->energyPoints--;
}
