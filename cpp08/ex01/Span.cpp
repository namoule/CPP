#include "Span.hpp"
#include <algorithm>

const char* Span::AlreadyFullException::what() const throw()
{
    return "Is already full";
}

const char* Span::NoSpanFound::what() const throw()

{
    return "No span found";
}


Span::Span(unsigned int N) : _storage(), _maxSize(N)
{
    _storage.reserve(N);
}

void Span::addNumber(int n)
{
    _storage.push_back(n);
}

template <typename T>
void Span::addRange(const T& range)
{
    typename T::const_iteratorstart i = range.begin();
    typename T::const_iterator end = range.end();
    for (; i != end; ++i)
    {
        if (_storage.size() >= this->_maxSize)
            throw AlreadyFullException();
        _storage.push_back(*i);
    }
}


unsigned long Span::shortestSpan()
{
    size_t stsspn;
    for(size_t i = 0; i < _maxSize - 1; i++)
    {
        size_t diff = std::abs(_storage[i] - _storage[i+1]);
        if(diff < stsspn)
            stsspn = diff;
    }
    return stsspn;
}



unsigned long Span::longestSpan()
{
    size_t lgstspn;
    for(size_t i = 0; i < _maxSize - 1; i++)
    {
        size_t diff = std::abs(_storage[i] - _storage[i+1]);
        if(diff > lgstspn)
            lgstspn = diff;
    }
    return lgstspn;
} 