#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <iostream>

class Animal
{
    public :
        Animal();
        Animal(std::string name);
        Animal(std::string name, std::string scream);
        ~Animal();
        void makeSound();
        void setScream(const std::string newScream);
        void setType(const std::string newType);
        std::string name;
    protected:
        std::string _type;
};

#endif