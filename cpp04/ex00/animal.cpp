#include "Animal_class.hpp"

Animal::Animal()
{
    std::cout << "constructor called" << std::endl;
}

Animal::~Animal()
{
    if (this->name.empty())
        std::cout << "OH MY GOD MY ANIMAL DIED........" << std::endl;
    else
        std::cout << "OH MY GOD MY " << this->name << std::endl;
}

Animal::Animal(std::string name)
{
    this->name = name;
    std::cout << "An animal : " << name << " have been created !"<<std::endl;
}

void Animal::makeNoise()
{
    if (this->_scream.empty())
        std::cout << "moooooooooooh (just 'cause all animals mooooh in my world)" << std::endl;
    else
        std::cout << this->_scream << std::endl;
}


