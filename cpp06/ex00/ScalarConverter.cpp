#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static bool	isPrintableChar(int c)
{
	return (c >= 32 && c <= 126);
}

void ScalarConverter::convert(std::string const &value)
{
	double	d;
	bool	isCharvalue;
	char	*endptr;

	d = 0.0;
	isCharvalue = false;
    (void)isCharvalue;
	if (value.length() == 1 && !std::isdigit(value[0]))
	{
		isCharvalue = true;
		d = static_cast<double>(value[0]);
	}
    else
	{
		endptr = NULL;
		d = std::strtod(value.c_str(), &endptr);
		if (*endptr && *endptr != 'f')
		{
			std::cout << "Invalid input.\n";
			return ;
		}
	}
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!isPrintableChar(static_cast<int>(d)))
		std::cout << "non printable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d)
		|| d < static_cast<double>(std::numeric_limits<int>::min())
		|| d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}
