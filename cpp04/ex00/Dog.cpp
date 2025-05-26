#include "Dog_class.hpp"

Dog::Dog()
{
    std::cout << "Oh its such a good puppy !" << std::endl;
}

Dog::Dog(std::string type)
{
    std::cout << "Oh its such a good " << type<< " !" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Oh the little doggo just fell asleep, so cute." << std::endl;
}

