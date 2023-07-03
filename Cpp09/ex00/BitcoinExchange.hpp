#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
    public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copyB);
    BitcoinExchange &operator=(const BitcoinExchange &copyB);
    ~BitcoinExchange();

    void CheckFile(std::string file_name);
    void parse_datacsv();
};

#endif
