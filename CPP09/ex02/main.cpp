#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        // PmergeMe sorter;
        // sorter.run(argc, argv);

        
        PmergeMe sorter(argc, argv);
    }
    catch (std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}