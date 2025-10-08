#include "A.hpp"

A::A()
{
    _type = 'A';
    std::cout << "Class created : " << _type << std::endl;
}

A::~A()
{
    std::cout << "Class closed : " << this->_type << std::endl;
}