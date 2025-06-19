#include "CharacterClass.hpp"
#include "IceClass.hpp"
#include "CureClass.hpp"
#include "MateriaSourceClass.hpp"
#include <iostream>

#include "CharacterClass.hpp"
#include "IceClass.hpp"
#include "CureClass.hpp"
#include "MateriaSourceClass.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Materia Source and learning Materia ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Creating Character 'me' and equipping Materia ===" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");
    AMateria* cure2 = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire");

    me->equip(ice);
    me->equip(cure1);
    me->equip(cure2);
    me->equip(unknown);

    std::cout << "\n=== Creating Character 'bob' and using Materia ===" << std::endl;
    ICharacter* bob = new Character("bob");

    me->use(0, *bob); // Ice
    me->use(1, *bob); // Cure
    me->use(2, *bob); // Cure
    me->use(3, *bob); // unknown

    std::cout << "\n=== Testing unequip ===" << std::endl;
    me->unequip(1);
    me->use(1, *bob);

    // delete cure1;
    delete me;
    delete bob;
    delete src;
    return 0;
}
