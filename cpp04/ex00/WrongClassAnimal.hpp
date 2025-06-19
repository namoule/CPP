#ifndef WRONG_ANIMAL_CLASS_HPP
#define WRONG_ANIMAL_CLASS_HPP

#include <iostream>

class WrongAnimal
{
    public :
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(std::string name, std::string scream);
        ~WrongAnimal();
        void makeSound();
        void setScream(const std::string newScream);
        void setType(const std::string newType);
        std::string name;
    protected:
        std::string _type;
        std::string _scream;
};

#endif