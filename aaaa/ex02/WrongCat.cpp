#include "WrongCatClass.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "[Wrong cat] A " << this->_type << " have been created." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[Wrong Cat] A " << this->_type << " died." << std::endl;
}