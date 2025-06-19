#include "AnimalClass.hpp"
#include "CatClass.hpp"
#include "Dogclass.hpp"
#include "WrongAnimalclass.hpp"
#include "WrongCatClass.hpp"
int main()
{
    // Animal animal;
    // animal.makeSound();
    // Animal cow((std::string)"cow");
    // cow.makeSound();
    // Cat cat;
    // cat.makeSound();
    // Dog dog;
    // dog.makeSound();
    // std::cout << "cat type is [" << cat.getType() << "] and Dog type is [" << dog.getType() << "]" << std::endl;
    // WrongAnimal wronganimal;
    // wronganimal.makeSound();
    // WrongCat wrongcat;
    // wrongcat.makeSound();

    Animal* p = new Cat();
    p->makeSound();
    delete p;
    Animal* q = new Dog();
    q->makeSound();
    delete q;
    WrongAnimal* r = new WrongCat();
    r->makeSound();
    delete r;
    WrongCat s;
    s.makeSound();
    return(0);
}