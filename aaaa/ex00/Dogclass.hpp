#ifndef DOGCLASS_HPP
#define DOGCLASS_HPP

#include "AnimalClass.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const;
        std::string getType() const;
};

#endif