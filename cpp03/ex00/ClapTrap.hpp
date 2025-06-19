#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private :
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        std::string _name;

    public :
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap(std::string _name);
        ~ClapTrap();

        void printValues();
};

#endif