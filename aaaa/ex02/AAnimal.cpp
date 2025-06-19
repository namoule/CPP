#include "AAnimalClass.hpp"

AAnimal::AAnimal()
{
    std::cout << "An Aanimal have been created !" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    this->_type = type;
    std::cout << "[AAnimal] An Aanimal have been created, its a : " << this->_type << std::endl;
}


AAnimal::~AAnimal()
{
    if(this->_type.empty())
        std::cout << "[AAnimal] An Aanimal died";
    else
        std::cout << "[AAnimal] " << this->_type << " died" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
