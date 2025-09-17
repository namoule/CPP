#include "Span.hpp"

template <typename T>
void Span::addRange(const T& range)
{
    typename T::const_iterator start = range.begin();
    typename T::const_iterator end = range.end();

    for (; start != end; ++start)
    {
        if (_storage.size() >= _maxSize)
            throw AlreadyFullException();
        _storage.push_back(*start);
    }
}