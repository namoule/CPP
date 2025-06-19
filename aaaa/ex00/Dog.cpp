#include "Dogclass.hpp"


Dog::Dog()
{
    this->_type = (std::string)"Dog";
    std::cout << "[Dog] A " << this->_type << " have been created." << std::endl;
}


Dog::~Dog()
{
    std::cout << "[Dog] A " << this->_type << " died." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] wof wof (but in a dumb version because dogs are cute but dumbs)" << std::endl;
}

std::string Dog::getType()  const
{
    return(this->_type);
}

Dog& Dog::operator=(const Dog& other)
{
    if(!other._type.empty())
    {
        this->_type = other._type;
        std::cout << "[Dog] An " << this->_type << " have been created by copy" << std::endl;
    }
    else
        std::cout << "[Dog] A dog have been created by copy" << std::endl;
    return *this;
}

Dog::Dog(const Dog& other)
{
    *this = other;
    std::cout << "[Dog]] created by copy" << std::endl;
}