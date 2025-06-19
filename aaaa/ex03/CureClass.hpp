#ifndef CURECLASS_HPP
#define CURECLASS_HPP

#include "AMateriaClass.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &i);

    Cure &operator=(const Cure &i);

    AMateria *clone(void) const;
    void use(ICharacter &target);

    ~Cure();
};

#endif