#include "WrongCatClass.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "[Wrongcat] A " << this->_type << " have been created." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] A " << this->_type << " died." << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "[WrongCat] YAAAAAAAAAAAAAAAAH" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if(!other._type.empty())
    {
        this->_type = other._type;
        std::cout << "[WrongCat] An " << this->_type << " have been created by copy" << std::endl;
    }
    else
        std::cout << "[WrongCat] An wrongcat have been created by copy" << std::endl;
    return *this;
}