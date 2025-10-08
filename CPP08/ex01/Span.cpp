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


Span::Span() : _storage(), _maxSize(0) {}

Span::Span(unsigned int N) : _storage(), _maxSize(N)
{
    _storage.reserve(N);
}

Span::Span(const Span& other) : _storage(other._storage), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _storage = other._storage;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

// Fonctions membres

void Span::addNumber(int n)
{
    if (_storage.size() >= _maxSize)
        throw AlreadyFullException();
    _storage.push_back(n);
}



unsigned long Span::shortestSpan()
{
    if (_storage.size() < 2)
        throw NoSpanFound();

    std::vector<int> sorted(_storage);
    std::sort(sorted.begin(), sorted.end());

    unsigned long minSpan = static_cast<unsigned long>(sorted[1] - sorted[0]);

    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        unsigned long diff = static_cast<unsigned long>(sorted[i + 1] - sorted[i]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned long Span::longestSpan()
{
    if (_storage.size() < 2)
        throw NoSpanFound();

    int min = *std::min_element(_storage.begin(), _storage.end());
    int max = *std::max_element(_storage.begin(), _storage.end());
    return static_cast<unsigned long>(max - min);
}
