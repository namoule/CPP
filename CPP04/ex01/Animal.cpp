#include "AnimalClass.hpp"

Animal::Animal()
{
    std::cout << "animal constructor called" << std::endl;
}

Animal::~Animal()
{
    if (this->name.empty())
        std::cout << "OH MY GOD MY ANIMAL DIED........" << std::endl;
    else
        std::cout << "OH MY GOD MY " << this->name << " died !" << std::endl;
}

Animal::Animal(std::string name)
{
    this->name = name;
    std::cout << "An animal : " << name << " have been created !"<<std::endl;
}

void Animal::setType(const std::string newType)
{
    this->_type = newType;
    std::cout << "new type : " << this->_type << std::endl;
}

void Animal::makeSound()
{
    std::cout << "moooooooooooh (just 'cause all animals mooooh in my world)" << std::endl;
}


