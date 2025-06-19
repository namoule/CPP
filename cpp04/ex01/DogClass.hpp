#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "AnimalClass.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog(std::string type);
        Dog();
        ~Dog();
        std::string type;
        void makeSound();
};

#endif