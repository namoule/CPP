#include "Fixed.hpp"

const int Fixed::_fractionnalBv = 8;

Fixed::Fixed(): _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = x * 256;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = static_cast<int>(roundf(x * 256));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

int Fixed::getRawBits() const
{
    return this->_fixedPoint;
}

void Fixed::setRawBits(const int raw)
{
    this->_fixedPoint = raw;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &src)
        this->_fixedPoint = src.getRawBits();
    return *this;
}

float Fixed::toFloat() const
{
    return this->_fixedPoint / 256.0f;
}


int Fixed::toInt(void) const
{
    return this->_fixedPoint / 256;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
