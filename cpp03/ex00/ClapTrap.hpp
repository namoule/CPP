#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private :
        int _hit_points;
        int _energy_point;
        int _attack_damage;
        std::string name;

    public :
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        void attack(const std::string& target);
        ClapTrap(std::string name);
        ~ClapTrap();

        void print_values();
};

#endif