#ifndef DOGCLASS_HPP
#define DOGCLASS_HPP

#include "AnimalClass.hpp"
#include "BrainClass.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();

        void makeSound() const;

        Brain* getBrain() const;
};

#endif
