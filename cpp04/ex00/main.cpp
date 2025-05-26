#include "Dog_class.hpp"
#include "Cat_class.hpp"
#include "Animal_class.hpp"

int main()
{
    // std::cout << "hey" << std::endl;
    Animal cow("cow");
    cow.makeNoise();
    std::cout << "----------------------------------------------" << std::endl;
    Cat cat("black cat");
    cat.makeNoise();
    std::cout << "----------------------------------------------" << std::endl;
    Dog dog("dumb dog");
    dog.makeNoise();
    return(0);
}