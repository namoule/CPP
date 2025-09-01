#include "Array.hpp"

template <typename T>

Array<T>::Array() : _elements(nullptr)
{
}


template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]())
{
    for(int i = 0; i < other.size(); i++)
    _elements[i] = 0;
}

template <typename T>
Array<T>::Array(Array *other) : _elements(new T[other.size()]())
{
    for(int i = 0; i < other.size(); i++)
        _elements[i] = other->_elements[i];
}


template <typename T>
size_t Array<T>::size()
{
    for(size_t i; _elements[i])
        i++;
    return(i);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] _elements;
        _elements = new T[other.size()];
        for (size_t i = 0; i < other.size(); ++i)
            _elements[i] = other._elements[i];
    }
    return *this;
}

