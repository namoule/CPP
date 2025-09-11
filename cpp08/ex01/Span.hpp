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
        Span(unsigned int N);
        void addNumber(int n);
        template <typename T>
        void addRange(const T& range);
        size_t shortestSpan();
        size_t longestSpan();
};

#endif