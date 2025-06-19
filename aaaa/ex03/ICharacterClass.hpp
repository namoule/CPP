#ifndef ICHARACTERCLASS_HPP
#define ICHARACTERCLASS_HPP

#include <iostream>
#include <AMateriaClass.hpp>

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {} //[required]

    virtual std::string const &getName(void) = 0;      //[required]
    virtual void equip(AMateria *m) = 0;               //[required]
    virtual void unequip(int idx) = 0;                 //[required]
    virtual void use(int idx, ICharacter &target) = 0; //[required]
};

#endif