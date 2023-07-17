#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>
#include <limits.h>
#include <bits/stdc++.h>

class BitcoinExchange
{

    private:
    std::map<std::string, float> map;
    std::list<std::pair<std::string, std::string>>lst;
    std::list<std::pair<std::string, std::string>>res;

    public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copyB);
    BitcoinExchange &operator=(const BitcoinExchange &copyB);
    ~BitcoinExchange();

    void CheckFile(std::string file_name);
    void ParseDatacsv(const std::string file);
    void HandleInputFile(std::string file);
    void GetExchange();
    void GetResult();
    void FindValue(std::list<std::pair<std::string, std::string>>::iterator it);
    // int CheckValidDate(std::list<std::pair<std::string, std::string>>::iterator it);
};

#endif
