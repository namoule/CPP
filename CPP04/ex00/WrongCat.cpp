#include "WrongClassCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Oh its such a good kitty !" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "Oh its such a good " << type<< " !" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Oh the little kitty just fell asleep, so cute." << std::endl;
}
