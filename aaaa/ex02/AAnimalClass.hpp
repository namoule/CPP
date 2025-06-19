#ifndef AANIMALCLASS_HPP
#define AANIMALCLASS_HPP

#include <string>
#include <iostream>
class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal() = 0;
        virtual void makeSound() const = 0;
};

#endif