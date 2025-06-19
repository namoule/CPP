#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "AnimalClass.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
        Cat(std::string type);
        Cat();
        ~Cat();
        void makeSound();
        std::string getType();
    };

#endif