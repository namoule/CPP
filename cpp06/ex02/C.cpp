#include "C.hpp"

C::C()
{
    _type = 'C';
    std::cout << "Class created : " << _type << std::endl;
}

C::~C()
{
    std::cout << "Class closed : " << _type << std::endl;
}