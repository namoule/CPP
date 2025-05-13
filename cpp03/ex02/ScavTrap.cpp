#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->name = name;
    this->attack_damage = 20;
    this->hit_points = 100;
    this->energy_point = 50;
    this->_gate_keep_mode = false;
    std::cout << "default constructor ScavTrap called." << std::endl << std::endl << "Values have been updated :" << std::endl << this->attack_damage << " attacks damage." << std::endl << this->hit_points << " hits point" << std::endl  << this->energy_point << " energy points." << std::endl;;

}

ScavTrap::~ScavTrap()
{
        std::cout << name << " Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    if(this->_gate_keep_mode == false)
    {
        std::cout << "Guardian mode ON!" << std::endl;
        this->_gate_keep_mode = true;
    }
    else
    {
        std::cout << "Guardien mode OFF." << std::endl;
        this->_gate_keep_mode = false;
    }
}