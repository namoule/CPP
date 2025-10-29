#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>
#include <iostream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _btc;

    bool isLeapYear(int year) const;
    bool isValidDate(int year, int month, int day) const;
    bool parseDate(const std::string& date, int& year, int& month, int& day) const;

    void getValues(const std::string& data_file);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void printBtc() const;
    void results(const std::string& filename) const;

    class FileOpenException;
};

#endif
