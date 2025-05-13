#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& wpn);
        ~HumanA();
        void attack() const;
    private:
        Weapon& _wpn;
        std::string name;
};

#endif
