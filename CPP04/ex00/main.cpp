#include "DogClass.hpp"
#include "CatClass.hpp"
#include "AnimalClass.hpp"
#include "WrongClassAnimal.hpp"
#include "WrongClassCat.hpp"

int main()
{
    std::cout << "----------------------------------------------" << std::endl;
    Animal cow("cow"); //animal created and type set to cow
    cow.makeSound();
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    Cat cat("black cat"); // black cat created
    cat.makeSound();
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    Dog dog("golden retriever"); // black dog created
    dog.makeSound();
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    WrongAnimal wrongCow("WrongCow"); //animal created and type set to wrongCow
    wrongCow.makeSound();
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    WrongCat Wrongcat("black Wrongcat"); // black Wrongcat created
    Wrongcat.makeSound();
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    return(0);
}