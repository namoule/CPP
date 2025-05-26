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
        void makeNoise();
        std::string name;
        std::string type;
    private:
        std::string _scream;
};

#endif