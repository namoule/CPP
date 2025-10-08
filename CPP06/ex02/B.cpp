#include "B.hpp"

B::B()
{
    _type = 'B';
    std::cout << "Class created : " << _type << std::endl;
}

B::~B()
{
    std::cout << "Class closed : " << _type << std::endl;
}