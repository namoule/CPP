#include "CatClass.hpp"

Cat::Cat()
{
    this->_type = (std::string)"Cat";
    std::cout << "[Cat] A " << this->_type <<" have been created" << std::endl;
}
Cat::~Cat()
{
    std::cout << "[Cat] A cat died" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "[Cat] MEOW MEOW (big meow because mine is obese)" << std::endl;
}

std::string Cat::getType() const
{
    return(this->_type);
}


Cat& Cat::operator=(const Cat& other)
{
    if(!other._type.empty())
    {
        this->_type = other._type;
        std::cout << "[Cat] An " << this->_type << " have been created by copy" << std::endl;
    }
    else
        std::cout << "[Cat] An cat have been created by copy" << std::endl;
    return *this;
}

Cat::Cat(const Cat& other)
{
    *this = other;
    std::cout << "[Cat] A " << this->_type << " have been created by copy" << std::endl;
}