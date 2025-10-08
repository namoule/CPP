#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (const Span::AlreadyFullException& e)
    {
        std::cout << e.what() << std::endl;
    }

    Span sp2(10);
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);
    sp2.addRange(vec);

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    try
    {
        Span sp3(1);
        sp3.addNumber(100);
        std::cout << sp3.shortestSpan() << std::endl;
    }
    catch (const Span::NoSpanFound& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
