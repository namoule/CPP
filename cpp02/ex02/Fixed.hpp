#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    private :
        int _fixedPoint;
        static const int _fractionnalBv;
    public :
        Fixed(void);
        Fixed(const int x);
        Fixed(const float x);
        Fixed(const Fixed &copy);
        Fixed &operator=(Fixed const &src);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;

        Fixed operator+(const Fixed& other) const; // [v]
        Fixed operator-(const Fixed& other) const; // [v]
        Fixed operator*(const Fixed& other) const; // [v]
        Fixed operator/(const Fixed& other) const; // [v]

        // Pré-incrément (++a)
        Fixed& operator++(); // [v]
        // Post-incrément (a++) 
        Fixed operator++(int); // [v]
        // Pré-décrément (--a) 
        Fixed& operator--(); // [v]
        // Post-décrément (a--)
        Fixed operator--(int); // [v]

        int getOther() const;
        bool operator==(const Fixed& other) const; // [v]
        bool operator!=(const Fixed& other) const; // [v]
        bool operator<(const Fixed& other) const; // [v]
        bool operator>(const Fixed& other) const; // [v]
        bool operator<=(const Fixed& other) const; // [v]
        bool operator>=(const Fixed& other) const; // [v]

        static Fixed		&min(Fixed &a, Fixed &b); //[v]
        static const Fixed	&min(const Fixed &a, const Fixed &b); //[v]
        static Fixed		&max(Fixed &a, Fixed &b); //[v]
        static const Fixed	&max(const Fixed &a, const Fixed &b); //[v]
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
