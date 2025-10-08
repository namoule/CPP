#include "RPN.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./rpn <RPN expression>" << std::endl;
        return 1;
    }

    std::stringstream ss;
    for (int i = 1; i < argc; ++i)
    {
        ss << argv[i];
        if (i < argc - 1)
            ss << " ";
    }

    try
    {
        RPN rpn(ss.str());
        std::cout << "Result: " << rpn.getResult() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
