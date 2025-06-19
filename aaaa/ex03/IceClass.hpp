#ifndef ICECLASS_HPP
#define ICECLASS_HPP

#include "AMateriaClass.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(const Ice &i);
    ~Ice();
    AMateria *clone(void) const;
    void use(ICharacter &target);
    Ice &operator=(const Ice &i);
};


#endif