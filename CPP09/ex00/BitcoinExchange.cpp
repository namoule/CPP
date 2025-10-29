#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <cctype>
#include <algorithm>

class BitcoinExchange::FileOpenException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Error: Unable to open file.";
    }
};

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return year % 4 == 0;
}

bool BitcoinExchange::isValidDate(int year, int month, int day) const
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year))
        maxDay = 29;

    return day <= maxDay;
}

bool BitcoinExchange::parseDate(const std::string &date, int &year, int &month, int &day) const
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    std::istringstream issYear(date.substr(0, 4));
    std::istringstream issMonth(date.substr(5, 2));
    std::istringstream issDay(date.substr(8, 2));
    if (!(issYear >> year))
        return false;
    if (!(issMonth >> month))
        return false;
    if (!(issDay >> day))
        return false;

    return isValidDate(year, month, day);
}
void BitcoinExchange::getValues(const std::string &data_file)
{
    std::ifstream file(data_file.c_str());
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string::size_type pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cerr << "Invalid line in data file: " << line << std::endl;
            continue;
        }

        std::string key = line.substr(0, pos);
        int y, m, d;
        if (!parseDate(key, y, m, d))
        {
            std::cerr << "Invalid date in data file: " << key << std::endl;
            continue;
        }

        std::string valueStr = line.substr(pos + 1);
        std::istringstream iss(valueStr);
        float value;
        if (!(iss >> value))
        {
            std::cerr << "Invalid value in data file for date " << key << std::endl;
            continue;
        }

        _btc[key] = value;
    }
}

BitcoinExchange::BitcoinExchange()
{
    getValues("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _btc = other._btc;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _btc = other._btc;
    return *this;
}

void BitcoinExchange::printBtc() const
{
    for (std::map<std::string, float>::const_iterator it = _btc.begin(); it != _btc.end(); ++it)
    {
        std::cout << "[" << it->first << "] : " << it->second << std::endl;
    }
}

static void trim(std::string &s)
{
    std::string::size_type start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
    {
        s.clear();
        return;
    }
    s = s.substr(start);
    std::string::size_type end = s.find_last_not_of(" \t");
    s = s.substr(0, end + 1);
}

void BitcoinExchange::results(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t sep = line.find('|');
        if (sep == std::string::npos)
        {
            trim(line);
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        trim(date);
        trim(valueStr);

        int y, m, d;
        if (!parseDate(date, y, m, d))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::istringstream valStream(valueStr);
        double value;
        valStream >> value;

        if (valStream.fail() || !valStream.eof())
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > INT_MAX)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::const_iterator it = _btc.lower_bound(date);

        if (it == _btc.end() || it->first != date)
        {
            if (it != _btc.begin())
                --it;
            else
            {
                std::cout << "Error: no available data for date " << date << std::endl;
                continue;
            }
        }

        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}
