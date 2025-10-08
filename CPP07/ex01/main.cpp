#include <iostream>
#include <string>
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before increment:\n";
    iter(arr, len, &printElement<int>);

    iter(arr, len, &increment<int>);

    std::cout << "After increment:\n";
    iter(arr, len, &printElement<int>);

    std::string strArr[] = {"Hello", "world", "!"};
    size_t lenStr = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "\nString array:\n";
    iter(strArr, lenStr, &printElement<std::string>);

    const int constArr[] = {10, 20, 30};
    size_t lenConst = sizeof(constArr) / sizeof(constArr[0]);

    std::cout << "\nConst array:\n";
    iter(constArr, lenConst, &printElement<int>); // ✅ OK

    return 0;
}
