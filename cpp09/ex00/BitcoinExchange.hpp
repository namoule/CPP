#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
    public:
    class FileOpenException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Error: could not open file.";
            }
    };

        BitcoinExchange();

        ~BitcoinExchange();

        BitcoinExchange(const BitcoinExchange& other);

        BitcoinExchange& operator=(const BitcoinExchange& other);

        void PrintBtc();
        bool ParseKey(std::string key) const;
        void getValues(const std::string &data);
        void results(const std::string &filename);

    private:
        std::map<std::string, float> _btc;
};

#endif
