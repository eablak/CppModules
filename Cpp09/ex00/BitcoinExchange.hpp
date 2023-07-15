#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>


class BitcoinExchange
{

    private:
    std::map<std::string, float> map;
    std::multimap<std::string, std::string>multimap;

    public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copyB);
    BitcoinExchange &operator=(const BitcoinExchange &copyB);
    ~BitcoinExchange();

    void CheckFile(std::string file_name);
    void ParseDatacsv(const std::string file);
    void HandleInputFile(std::string file);
};

#endif
