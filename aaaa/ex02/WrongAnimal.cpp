#include "WrongAnimalclass.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = (std::string)"WrongAnimal";
    std::cout << "[Wrong Animal] A " << this->_type << " have been created." << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] A " << this->_type << " died";
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] hoooooooom (same mooh world but it is doing it wrong)" << std::endl;
}