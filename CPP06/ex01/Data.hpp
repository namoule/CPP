#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
    private:
        int _value;
        Data();
    public:
        explicit Data(int value);
        Data(const Data &other);
        Data &operator=(const Data &other);
        ~Data();
        int getValue() const;
};

#endif