#include "AnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"
#include "WrongAnimalclass.hpp"
#include "WrongCatClass.hpp"
#include "AnimalClass.hpp"

int main()
{
    std::cout << " Canonical Form Tests " << std::endl;

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;

    std::cout << "\n Polymorphism Tests " << std::endl;

    const Animal* a1 = new Cat();
    const Animal* a2 = new Dog();
    a1->makeSound();
    a2->makeSound();
    delete a1;
    delete a2;

    std::cout << "\n WrongAnimal Polymorphism Test " << std::endl;

    const WrongAnimal* wa = new WrongCat();
    wa->makeSound();
    delete wa;


    std::cout << "\n destructor time" << std::endl;
    return 0;
}
