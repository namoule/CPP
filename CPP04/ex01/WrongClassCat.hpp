#ifndef WRONG_CAT_CLASS_HPP
#define WRONG_CAT_CLASS_HPP

#include "WrongClassAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(std::string type);
        WrongCat();
        ~WrongCat();
    };

#endif