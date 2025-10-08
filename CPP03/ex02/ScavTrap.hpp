#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        std::string name;
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        void attack(const std::string &target);
        void guardGate();
    private:
        bool _gate_keep_mode;
};

#endif