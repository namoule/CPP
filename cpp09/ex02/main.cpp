#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        PmergeMe sorter;
        sorter.parseInput(argc, argv);
        sorter.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}