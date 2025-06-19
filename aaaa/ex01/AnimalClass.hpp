#ifndef ANIMALCLASS_HPP
#define ANIMALCLASS_HPP

#include <string>
#include <iostream>
class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual Animal operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const;
};

#endif