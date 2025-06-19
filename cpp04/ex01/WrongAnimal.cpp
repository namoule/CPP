#include "WrongClassAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Wronganimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    if (this->name.empty())
        std::cout << "OH MY GOD MY WrongANIMAL DIED........" << std::endl;
    else
        std::cout << "OH MY GOD MY " << this->name << " died !" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
    this->name = name;
    std::cout << "An Wronganimal : " << name << " have been created !"<<std::endl;
}

void WrongAnimal::setScream(const std::string newScream)
{
    if(!this->_scream.empty())
        std::cout << "scream of the Wronganimal changed from : " << this->_scream << ", to : ";
    else
        std::cout << "scream of the Wronganimal set to : ";
    
    this->_scream = newScream;
    std::cout << this->_scream << std::endl;
}

void WrongAnimal::setType(const std::string newType)
{
    this->_type = newType;
    std::cout << "new type : " << this->_type << std::endl;
}

void WrongAnimal::makeSound()
{
    std::cout << "wrong moooooooooooh (just 'cause all wrong animals wrong mooooh in my world)" << std::endl;
}


