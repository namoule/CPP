#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        int hit_points;
        int energy_point;
        int attack_damage;
        std::string name;

    public :
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        virtual void attack(const std::string& target);
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();

        void print_values();
};

#endif