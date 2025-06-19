#include "AnimalClass.hpp"

Animal::Animal()
{
    std::cout << "An animal have been created !" << std::endl;
}

Animal::Animal(std::string type)
{
    this->_type = type;
    std::cout << "[Animal] An animal have been created, its a : " << this->_type << std::endl;
}


Animal::~Animal()
{
    if(this->_type.empty())
        std::cout << "[Animal] An animal died" << std::endl;
    else
        std::cout << "[Animal] " << this->_type << " died" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] Mooooooooh ('cause in my world every animal mooh)" << std::endl;
}

Animal Animal::operator=(const Animal& other)
{
    if(!other._type.empty())
    {
        this->_type = other._type;
        std::cout << "[Animal] An " << this->_type << " have been created by copy" << std::endl;
    }
    else
        std::cout << "[Animal] An animal have been created by copy" << std::endl;
    return *this;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "[ANIMAL] An " << this->_type << " have been created by copy" << std::endl;
}