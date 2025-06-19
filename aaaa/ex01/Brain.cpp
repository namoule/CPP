#include "BrainClass.hpp"

Brain::Brain()
{
    std::cout << "[Brain] A brain have been created." << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "[Brain] A brain have been created by copy." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, std::string newidea)
{
    if (index >= 0 && index < 100)
        _ideas[index] = newidea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "";
}
