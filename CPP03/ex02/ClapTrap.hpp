#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        std::string _name;

    public :
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        void attack(const std::string& target);
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();

        void printValues();
};

#endif