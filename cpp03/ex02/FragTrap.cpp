#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->name = name;
    this->attack_damage = 30;
    this->hit_points = 100;
    this->energy_point = 100;
    this->_gate_keep_mode = false;
    std::cout << "default constructor FragTrap called." << std::endl << std::endl << "Values have been updated :" << std::endl << this->attack_damage << " attacks damage." << std::endl << this->hit_points << " hits point" << std::endl  << this->energy_point << " energy points." << std::endl;;
}

FragTrap::~FragTrap()
{
        std::cout << name <<" Destructor called" << std::endl;
}

void FragTrap::highFiveGuys()
{
    std::cout << "Awesome ! Let's High Five now !" <<std::endl;
}