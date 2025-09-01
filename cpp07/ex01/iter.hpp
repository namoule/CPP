#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename Func> void iter(T *adress, size_t lenght, Func function)
{
    for(size_t i = 0; i < lenght; i++)
    {
        function(adress[i]);
    }
}

#endif