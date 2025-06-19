#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
    public:
        std::string _name;
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        void attack(const std::string &target);
        void highFiveGuys();
    private:
        bool _gateKeepMode;
};

#endif