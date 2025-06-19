#ifndef WRONGCATCLASS_HPP
#define WRONGCATCLASS_HPP

#include "WrongAnimalclass.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        void makeSound();
};

#endif