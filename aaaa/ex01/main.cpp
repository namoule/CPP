#include "AnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"
#include "WrongAnimalclass.hpp"
#include "WrongCatClass.hpp"
#include <iostream>

int main()
{
    std::cout << "*Canonical Form + Brain Copy Test*\n" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Chase the laser pointer");
    cat1.getBrain()->setIdea(1, "Nap in the sun");
    Cat cat2(cat1);
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
    Cat cat3;
    cat3 = cat1;
    std::cout << "Cat3 idea[1]: " << cat3.getBrain()->getIdea(1) << std::endl;


    std::cout << "\n*Polymorphism with Animal*\n" << std::endl;
    const Animal* a1 = new Dog();
    const Animal* a2 = new Cat();
    a1->makeSound();
    a2->makeSound();
    delete a1;
    delete a2;

    std::cout << "\nWrongAnimal Polymorphism Test\n" << std::endl;
    const WrongAnimal* wa = new WrongCat();
    wa->makeSound();
    delete wa;

    std::cout << "\n Deep Copy Validation \n" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "bang my head over a door");
    Dog dog2(dog1);
    std::cout << "Dog1 brain idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 brain idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    dog2.getBrain()->setIdea(0, "bang my head over a chair");
    std::cout << "Dog1 brain idea after (no) change: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 brain idea after change: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}

