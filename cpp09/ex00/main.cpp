#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argc, (void)argv;
    if(argc != 2)
        return(-1);
    BitcoinExchange a;
    // a.PrintBtc();
    a.results("input.txt");
    return(0);
}