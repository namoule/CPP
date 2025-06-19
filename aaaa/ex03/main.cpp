#include "CharacterClass.hpp"
#include "IceClass.hpp"
#include "CureClass.hpp"
#include "MateriaSourceClass.hpp"
#include <iostream>



/*
void faireVoler(Volant* objet)
{
    objet->voler();  // Exemle pour interet classe abstraite et interface
}
*/


int main()
{
    IMateriaSource* src= new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());


    ICharacter* me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure"); // 5 donc pb
    me->equip(tmp);
    delete tmp;
    ICharacter* bob = new Character("bob");
    me->use(4, *bob);
    
    //-----------------------------------------------/ unequip part
    // bob->use(3, *bob);
    // bob->unequip(0);
    // tmp = src->createMateria("ice");
    // bob->equip(tmp);
    // bob->unequip(0);
    // delete tmp;

    //-----------------------------------------------/ unequip part

    bob->use(0, *bob);
    me->use(0, *bob);
    me->use(1, *bob);

    delete me;
    delete bob;
    delete src;

    //--------------------------------------------------------//

    // Character a("A");

    // AMateria* ice = new Ice();
    // AMateria* cure = new Cure();

    // a.equip(ice);
    // a.equip(cure);

    // Character b(a);

    // Character c("C");
    // c = a;

    // a.use(0, a);
    // a.use(1, a);

    // b.use(0, a);
    // b.use(1, a);

    // c.use(0, a);
    // c.use(1, a);
    return 0;
}
