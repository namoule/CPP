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
    std::cout << "default constructor ScavTrap called and the given attacks damage are : " << this->attack_damage << ", " << this->hit_points << " hits points, " << this->energy_point << " energy points." << std::endl;
}

ScavTrap::~ScavTrap()
{
        std::cout << "ScavTrap died with :" << this->hit_points << " hit_points, " << this->attack_damage << " attack damage, " << this->energy_point << " energy points." << std::endl;
}

void ScavTrap::guardGate()
{
    if(this->_gate_keep_mode == false)
    {
        std::cout << "Guardian mode activated !" << std::endl;
        this->_gate_keep_mode = true;
    }
    else
    {
        std::cout << "Guardien mode disabled." << std::endl;
        this->_gate_keep_mode = false;
    }
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << name << " utilise son attaque spéciale contre " << target << " ! Et lui enleve : " << this->attack_damage << " damage points" << std::endl;
    this->energy_point--;
}
