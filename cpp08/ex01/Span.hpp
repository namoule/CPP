#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
private:
    std::vector<int> _storage;
    unsigned int _maxSize;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    class AlreadyFullException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanFound : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    void addNumber(int n);

    template <typename T>
    void addRange(const T& range);

    unsigned long shortestSpan();
    unsigned long longestSpan();
};

#include "Span.tpp"

#endif
