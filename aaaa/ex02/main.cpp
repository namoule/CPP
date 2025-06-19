#include "AAnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"

#include "AAnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"
#include "WrongAnimalclass.hpp"
#include "WrongCatClass.hpp"
#include <iostream>

int main()
{
    std::cout << "Canonical Form + Brain Copy Test" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Catch the red dot");
    cat1.getBrain()->setIdea(1, "Climb the curtain");
    Cat cat2(cat1);
    std::cout << "\nCat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
    Cat cat3;
    cat3 = cat1;
    std::cout << "\nCat3 idea[1]: " << cat3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\nPolymorphism with AAnimal*" << std::endl;
    const AAnimal* a1 = new Dog();
    const AAnimal* a2 = new Cat();
    a1->makeSound();
    a2->makeSound();
    delete a1;
    delete a2;

    std::cout << "\nWrongAnimal Polymorphism Test" << std::endl;
    const WrongAnimal* wa = new WrongCat();
    wa->makeSound();
    delete wa;

    std::cout << "\nDeep Copy Validation" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "bang my head over a door");
    Dog dog2(dog1);
    std::cout << "\nDog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "\nDog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    dog2.getBrain()->setIdea(0, "bang my head over a chai");
    std::cout << "\nDog1 idea[0] after (no) change: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "\nDog2 idea[0] after change: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
