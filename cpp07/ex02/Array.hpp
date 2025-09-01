#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
    public:
    T *_elements;
    
    class OutOfBounds : public std::exception 
    {
        public:
                virtual const char* what() const throw();
    };

    Array();
    Array(unsigned int n);
    Array(Array *other);
    Array& operator=(const Array& other);
    ~Array();
    size_t size();

};

#endif