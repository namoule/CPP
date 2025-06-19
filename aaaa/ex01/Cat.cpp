#include "CatClass.hpp"

Cat::Cat() : brain(new Brain())
{
    _type = (std::string)"Cat";
    std::cout << "[Cat] A " << _type <<" have been created" << std::endl;
}

Cat::Cat(const Cat& other)
{
    brain = new Brain(*other.brain);
    _type = other._type;
    std::cout << "[Cat copy] Cat created by copy." << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] A cat died" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "[Cat] MEOW MEOW (big meow because mine is obese)" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        _type = other._type;
    }
    return *this;
}

Brain* Cat::getBrain() const 
{
    return brain;
}
