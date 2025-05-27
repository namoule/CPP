#include "Fixed.hpp"

Fixed::Fixed()
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


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &src)
        this->_fixedPoint = src.getRawBits();
    return *this;
}
void Fixed::setRawBits(const int raw)
{
    std::cout <<"Set raw bits called" << std::endl;
    this->_fixedPoint = raw;
    return;
}