#ifndef WRONGCATCLASS_HPP
#define WRONGCATCLASS_HPP

#include "WrongAnimalclass.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat& operator=(const WrongCat& other);

};

#endif