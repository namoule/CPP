#include "whatever.hpp"

int main(void)
{
    int a = 1;
    int b = 4;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;


    char e = 'a';
    char f = 'a';

    std::cout << "min : try equal value should return the second one = " << ::min(e, f) << std::endl;
    std::cout << "max : try equal value should return the second one = " << ::max(e, f) << std::endl;

    return(0);
}