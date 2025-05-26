#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Animal_class.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog(std::string type);
        Dog();
        ~Dog();
        std::string type;
        void makeNoise(){std::cout << "wow wow (eyeballs are rolling while wowing because highly dumb)" << std::endl;}
};

#endif