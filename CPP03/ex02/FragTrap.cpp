#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name)
{
    this->_name = _name;
    this->_attackDamage = 30;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_gateKeepMode = false;
    std::cout << "default constructor FragTrap called." << std::endl << std::endl << "Values have been updated :" << std::endl << this->_attackDamage << " attacks damage." << std::endl << this->_hitPoints << " hits point" << std::endl  << this->_energyPoints << " energy points." << std::endl;;
}

FragTrap::~FragTrap()
{
        std::cout << _name <<" Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(this->_energyPoints <= 0)
        std::cout << this->_name << " has no more energy...." << std::endl;
    else
    {
        std::cout << "a frag trap named : " << this->_name << " attacked  : " << target << " with " << this->_attackDamage << " points" << std::endl;
        this->_energyPoints--;
    }
}

void FragTrap::highFiveGuys()
{
    std::cout << "Awesome ! Let's High Five now !" <<std::endl;
}