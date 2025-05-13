#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &src)
        this->_fixed_point = src.getRawBits();
    return *this;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed_point;
}

void Fixed::setRawBits(const int raw)
{
    std::cout <<"Set raw bits called" << std::endl;
    this->_fixed_point = raw;
    return;
}