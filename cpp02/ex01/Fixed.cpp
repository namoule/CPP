#include "Fixed.hpp"

const int Fixed::_fractionnal_bv = 8;

Fixed::Fixed(): _fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed_point = x * 256;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed_point = static_cast<int>(roundf(x * 256));
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
    return this->_fixed_point;
}

void Fixed::setRawBits(const int raw)
{
    this->_fixed_point = raw;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &src)
        this->_fixed_point = src.getRawBits();
    return *this;
}

float Fixed::toFloat() const
{
    return this->_fixed_point / 256.0f;
}


int Fixed::toInt(void) const  //divide by 256 to remove the fractional part and return to the original integer.
{
    return this->_fixed_point / 256;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) //is useful for writing the float number of the fixed class
{
    out << fixed.toFloat();
    return out;
}
