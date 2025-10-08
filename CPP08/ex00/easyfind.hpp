#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>


class NoIntegerArgumentFound : public std::exception 
{
    public:
        virtual const char* what() const throw();
};

template <typename T> typename T::iterator easyfind(T &a, int b);

#endif