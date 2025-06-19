#ifndef BRAINCLASS_HPP
#define BRAINCLASS_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain& operator=(const Brain& other);

        void setIdea(int index, std::string newidea);
        std::string getIdea(int index) const;
};

#endif