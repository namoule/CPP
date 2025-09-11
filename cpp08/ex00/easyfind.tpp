#include "easyfind.hpp"
#include <algorithm>

const char* NoIntergerArgumentFound::what() const throw()
{
    return "No Interger argument found in the container";
}

template <typename T> 
typename T::iterator easyfind(T &a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if(it == a.end())
        throw NoIntergerArgumentFound();
    return it;
}