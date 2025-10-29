#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argc, (void)argv;
    if(argc != 2)
        return(-1);
    try
    {
        BitcoinExchange a;
        a.results(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(0);
}