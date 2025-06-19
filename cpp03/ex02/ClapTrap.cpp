#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Clap Trap Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string given__name)
{
    this->_attackDamage = 0;
    this->_energyPoints = 10;
    this->_hitPoints = 10;
    std::cout << "ClapTrap : " << given__name << " have been created with "<< this->_energyPoints << " energy point, " << this->_hitPoints << " hit point and " << this->_attackDamage  << " attack damage" << std::endl;
    this->_name = given__name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : " << this->_name << " was a good soldier... With  "<< this->_energyPoints << " energy point, " << this->_hitPoints << " hit point and " << this->_attackDamage  << " attack damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_energyPoints - 1 < 0)
    {
        std::cout << this->_name << " has no more energy..."<< std::endl;
        return;
    }
    if(this->_hitPoints < 1)
    {

    }
    if((this->_hitPoints + amount) >= 10)
        this->_hitPoints = 10;
    else
        this->_hitPoints = this->_hitPoints + amount;
    this->_energyPoints--;
    std::cout << this->_name << " get " << amount << " points back : " << this->_hitPoints << " health points left" << " | Energy left : " << this->_energyPoints << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if(this->_hitPoints <= 0)
    {
        this->_hitPoints = 0;
        std::cout << this->_name << " just died..."<< std::endl;
        return;
    }
    std::cout << this->_name << " lost " << amount << " Health points : " << this->_hitPoints << " health points left..." << std::endl;
}

void ClapTrap::printValues()
{
    std::cout << "ClapTrap : " << this->_name << " has "<< this->_energyPoints << " energy point, " << this->_hitPoints << " hit point and " << this->_attackDamage  << " attack damage" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_energyPoints - 1 < 0)
    {
        std::cout << this->_name << " has no more energy..."<< std::endl;
        return;
    }
    if(this->_hitPoints < 1)
    {
        std::cout << this->_name << " died..."<< std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << this->_name << " attack " << target << " and makes him lost " << this->_attackDamage << " | Energy left : " << this->_energyPoints << std::endl;
}