#include "Fixed.hpp"

const int Fixed::_fractionnalBv = 8;

Fixed::Fixed(): _fixedPoint(0)
{
}

Fixed::Fixed(const int x)
{
    this->_fixedPoint = x * 256;
}

Fixed::Fixed(const float x)
{
	this->_fixedPoint = roundf(x * (1 << this->_fractionnalBv));
	return;
}


Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

int Fixed::getRawBits() const
{
    return this->_fixedPoint;
}

int Fixed::getOther() const
{
    return this->_fractionnalBv;
}

void Fixed::setRawBits(const int raw)
{
    this->_fixedPoint = raw;
}

Fixed &Fixed::operator=(Fixed const &src)
{
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



Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result._fixedPoint = this->_fixedPoint + other._fixedPoint;
    return result; 
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result._fixedPoint = this->_fixedPoint - other._fixedPoint;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result._fixedPoint = (this->_fixedPoint * other._fixedPoint) / 256;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result._fixedPoint = this->_fixedPoint / other._fixedPoint;
    return result;
}

bool Fixed::operator==(const Fixed& other) const
{
    return(this->_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return!(this->_fixedPoint == other._fixedPoint);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return(this->_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return(this->_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<(const Fixed& other) const
{
    return(this->_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>(const Fixed& other) const
{
    return(this->_fixedPoint > other._fixedPoint);
}

Fixed& Fixed::operator++() {
    _fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this; 
    _fixedPoint += 1;
    return temp;
}

Fixed& Fixed::operator--() 
{
    _fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _fixedPoint -= 1; 
    return temp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{


	if (a > b)
		return (a);
	return (b);
}
