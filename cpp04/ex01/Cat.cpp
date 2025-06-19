#include "CatClass.hpp"

Cat::Cat()
{
    std::cout << "Oh its such a good kitty !" << std::endl;
}

Cat::Cat(std::string type)
{
    std::cout << "Oh its such a good " << type<< " !" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Oh the little kitty just fell asleep, so cute." << std::endl;
}

void Cat::makeSound()
{
    std::cout << "MEOW MEOW (loud cat noise because mine is obese)" << std::endl;
}

std::string Cat::getType()
{
    return(this->_type);
}