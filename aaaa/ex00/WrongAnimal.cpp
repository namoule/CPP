#include "WrongAnimalclass.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = (std::string)"WrongAnimal";
    std::cout << "[Wrong`Animal] A " << this->_type << " have been created." << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] A " << this->_type << " died" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] hoooooooom (same mooh world but it is doing it wrong)" << std::endl;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal& other)
{
    if(!other._type.empty())
    {
        this->_type = other._type;
        std::cout << "[WrongAnimal] An " << this->_type << " have been created by copy" << std::endl;
    }
    else
        std::cout << "[WrongAnimal] An wronganimal have been created by copy" << std::endl;
    return *this;
}