#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Animal_class.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
        Cat(std::string type);
        Cat();
        ~Cat();
        std::string type;
        void makeNoise(){std::cout << "MEOW MEOW (obese cat noise because mine is obese)" << std::endl;}
};

#endif