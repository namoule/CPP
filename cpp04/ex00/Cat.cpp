#include "Cat_class.hpp"

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

