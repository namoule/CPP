#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int _fixed_point;
        static const int _fractionnal_bv;
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
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
