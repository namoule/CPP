#ifndef CATCLASS_HPP
#define CATCLASS_HPP

#include "AnimalClass.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        void makeSound() const;
        std::string getType() const;
};

#endif