#ifndef WRONGANIMALCLASS_HPP
#define WRONGANIMALCLASS_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        virtual ~WrongAnimal();
        virtual WrongAnimal operator=(const WrongAnimal& other);
        void makeSound() const;
};

#endif