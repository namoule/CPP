#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {
        PmergeMe DefaultConstructor;
        DefaultConstructor.run(argc, argv);
        // std::cout << "creation with arguments : " << std::endl;
        // PmergeMe withArguments(argc, argv);
    }
    catch (std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}