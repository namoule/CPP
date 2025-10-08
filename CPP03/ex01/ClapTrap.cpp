#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Clap Trap Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string given_name)
{
    this->attack_damage = 0;
    this->energy_point = 10;
    this->hit_points = 10;
    std::cout << "ClapTrap : " << given_name << " have been created with "<< this->energy_point << " energy point, " << this->hit_points << " hit point and " << this->attack_damage  << " attack damage" << std::endl;
    this->name = given_name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : " << this->name << " was a good soldier... With  "<< this->energy_point << " energy point, " << this->hit_points << " hit point and " << this->attack_damage  << " attack damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energy_point - 1 < 0)
    {
        std::cout << this->name << " has no more energy..."<< std::endl;
        return;
    }
    else
        this->hit_points = this->hit_points + amount;
    this->energy_point--;
    std::cout << this->name << " get " << amount << " points back : " << this->hit_points << " health points left" << " | Energy left : " << this->energy_point << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_points -= amount;
    if(this->hit_points <= 0)
    {
        this->hit_points = 0;
        std::cout << this->name << " just died..."<< std::endl;
        return;
    }
    std::cout << this->name << " lost " << amount << " Health points : " << this->hit_points << " health points left..." << std::endl;
}

void ClapTrap::print_values()
{
    std::cout << "ClapTrap : " << this->name << " has "<< this->energy_point << " energy point, " << this->hit_points << " hit point and " << this->attack_damage  << " attack damage" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->energy_point - 1 < 0)
    {
        std::cout << this->name << " has no more energy..."<< std::endl;
        return;
    }
    if(this->hit_points < 1)
    {
        std::cout << this->name << " died..."<< std::endl;
        return;
    }
    this->energy_point--;
    std::cout << this->name << " attack " << target << " and makes him lost " << this->attack_damage << " | Energy left : " << this->energy_point << std::endl;
}