#include "AAnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"

int main()
{
    // AAnimal animal;              // AAnimal est abstraite donc ne va pas compiler
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;
    return 0;
}