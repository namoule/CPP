#include "Fixed.hpp"

const int Fixed::_fractionnal_bv = 8;

Fixed::Fixed(): _fixed_point(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixed_point = x * 256;
}

Fixed::Fixed(const float x)
{
	//std::cout << "Float constructor called." << std::endl;
	this->_fixed_point = roundf(x * (1 << this->_fractionnal_bv));
	return;
}


Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

int Fixed::getRawBits() const
{
    return this->_fixed_point;
}

int Fixed::getOther() const
{
    return this->_fractionnal_bv;
}

void Fixed::setRawBits(const int raw)
{
    this->_fixed_point = raw;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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



Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result._fixed_point = this->_fixed_point + other._fixed_point;
    return result; 
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result._fixed_point = this->_fixed_point - other._fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result._fixed_point = (this->_fixed_point * other._fixed_point) / 256;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result._fixed_point = this->_fixed_point / other._fixed_point;
    return result;
}

bool Fixed::operator==(const Fixed& other) const
{
    return(this->_fixed_point == other._fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return!(this->_fixed_point == other._fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return(this->_fixed_point <= other._fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return(this->_fixed_point >= other._fixed_point);
}

bool Fixed::operator<(const Fixed& other) const
{
    return(this->_fixed_point < other._fixed_point);
}

bool Fixed::operator>(const Fixed& other) const
{
    return(this->_fixed_point > other._fixed_point);
}

Fixed& Fixed::operator++() {
    _fixed_point += 1;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this; 
    _fixed_point += 1;
    return temp;
}

Fixed& Fixed::operator--() 
{
    _fixed_point -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _fixed_point -= 1; 
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
