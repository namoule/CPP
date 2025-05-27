#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string given_name)
{
    this->_attack_damage = 0;
    this->_energy_point = 10;
    this->_hit_points = 10;
    std::cout << "ClapTrap : " << given_name << " have been created with "<< this->_energy_point << " energy point, " << this->_hit_points << " hit point and " << this->_attack_damage  << " attack damage" << std::endl;
    this->name = given_name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : " << this->name << " was a good soldier... With  "<< this->_energy_point << " energy point, " << this->_hit_points << " hit point and " << this->_attack_damage  << " attack damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_energy_point - 1 < 0)
    {
        std::cout << this->name << " has no more energy..."<< std::endl;
        return;
    }
    else
        this->_hit_points = this->_hit_points + amount;
    this->_energy_point--;
    std::cout << this->name << " get " << amount << " points back : " << this->_hit_points << " health points left" << " | Energy left : " << this->_energy_point << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_points -= amount;
    if(this->_hit_points <= 0)
    {
        this->_hit_points = 0;
        std::cout << this->name << " just died..."<< std::endl;
        return;
    }
    std::cout << this->name << " lost " << amount << " Health points : " << this->_hit_points << " health points left..." << std::endl;
}

void ClapTrap::print_values()
{
    std::cout << "ClapTrap : " << this->name << " has "<< this->_energy_point << " energy point, " << this->_hit_points << " hit point and " << this->_attack_damage  << " attack damage" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_energy_point - 1 < 0)
    {
        std::cout << this->name << " has no more energy..."<< std::endl;
        return;
    }
    if(this->_hit_points < 1)
    {
        std::cout << this->name << " died..."<< std::endl;
        return;
    }
    this->_energy_point--;
    std::cout << this->name << " attack " << target << " and makes him lost " << this->_attack_damage << " | Energy left : " << this->_energy_point << std::endl;
}