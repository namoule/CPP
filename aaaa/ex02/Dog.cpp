#include "Dogclass.hpp"


Dog::Dog() : brain(new Brain()) 
{
    this->_type = (std::string)"Dog";
    std::cout << "[Dog] A " << this->_type << " have been created." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "Dog copied" << std::endl;
    brain = new Brain(*other.brain);
    _type = other._type;
}

Dog::~Dog()
{
    std::cout << "[Dog] A " << this->_type << " died." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] wof wof (but in a dumb version because dogs are cute but dumbs)" << std::endl;
}


// Dog& Dog::operator=(const Dog& other)
// {
//     std::cout << "Dog assigned" << std::endl;
//     if (this != &other)
//     {
//         AAnimal::operator=(other);
//         delete brain;
//         brain = new Brain(*other.brain);
//         _type = other._type;
//     }
//     return *this;
// }

Brain* Dog::getBrain() const
{
    return brain;
}
