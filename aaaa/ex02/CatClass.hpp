#ifndef CATCLASS_HPP
#define CATCLASS_HPP

#include "AAnimalClass.hpp"
#include "BrainClass.hpp"
class Cat : public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        // Cat& operator=(const Cat& other);
        virtual ~Cat();
        Brain* getBrain() const; 
        void makeSound() const;
};

#endif