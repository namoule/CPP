#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    getValues("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->_btc = other._btc;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->_btc = other._btc;
    }
    return *this;
}

bool GoodDayInMonth(int day, int month)
{
    if(day < 0 || month < 0 || month > 12)
        return false;
    else if(month == 2 && (day > 29))
        return false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
        return false;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return false;
    return true;
}

bool BitcoinExchange::ParseKey(std::string key) const
{
    std::istringstream iss(key.substr(0, 4));
    int year, month, day;
    iss >> year;
    std::istringstream iss1(key.substr(5, 2));
    iss1 >> month;
    std::istringstream iss2(key.substr(8));
    iss2 >> day;
    if(GoodDayInMonth(day, month) == false || year < 0)
    {
        std::cout <<"wrong value " << key <<std::endl;
        return false;
    }
    return true;
}
void BitcoinExchange::getValues(const std::string& data_file)
{
    std::ifstream file(data_file);
    std::string line;
    getline(file, line);
    while(getline(file, line))
    {
        std::string::size_type pos = line.find(',');
        std::string key = line.substr(0, pos);
        if (ParseKey(key) == false)
        {
            std::cout << "wrong date" << key << std::endl;
            continue;
        }
        std::istringstream iss(line.substr(pos+1));
        float value;
        if(iss >> value)
        {
            this->_btc[key] = value;
        }
        else
        {
            std::cerr << "not a number" << std::endl;
        }
    }

}

void BitcoinExchange::PrintBtc()
{
    for(std::map<std::string, float>::iterator it = _btc.begin(); it != _btc.end(); ++it)
        std::cout << "[" << it->first << "]" << "   :   " << it->second << std::endl;
}

void trim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos)
    {
        str = "";
    }
    else
    {
        str = str.substr(start, end - start + 1);
    }
}

void BitcoinExchange::results(const std::string &filename)
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
        if (!ParseKey(date))
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
                continue;
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}