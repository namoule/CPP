#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 10;
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	Array<int> b = a;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	return (0);
}
