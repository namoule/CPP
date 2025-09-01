#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increment(T& element)
{
    ++element;
}


int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Avant incrémentation :" << std::endl;
    ::iter(intArray, intLength, printElement<int>);

    ::iter(intArray, intLength, increment<int>);

    std::cout << "Après incrémentation :" << std::endl;
    ::iter(intArray, intLength, printElement<int>);

    std::string strArray[] = {"Hello", "world", "!"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "\nAffichage des chaînes :" << std::endl;
    ::iter(strArray, strLength, printElement<std::string>);

    return 0;
}
