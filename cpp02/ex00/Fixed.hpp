#ifndef FIXED_CPP
#define FIXED_CPP

#include <iostream>

class Fixed{
    private :
        int _fixed_point;
        static const int _fractionnal_point = 8;
    public :
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);

        Fixed &operator=(Fixed const &src);

        int getRawBits(void) const;
        void setRawBits(const int raw);
};

#endif