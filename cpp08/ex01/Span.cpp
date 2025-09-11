#include "Span.hpp"

const char* Span::AlreadyFullException::what() const throw()
{
    return "Is already full";
}

const char* Span::NoSpanFound::what() const throw()

{
    return "No span found";
}

#include "Span.hpp"

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

size_t Span::shortestSpan()
{
    return 0;
}

size_t Span::longestSpan()
{
    return 0;
}