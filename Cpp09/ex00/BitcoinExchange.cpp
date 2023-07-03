#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyB){ *this = copyB; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copyB) 
{(void) copyB; return (*this);} //

void BitcoinExchange::CheckFile(std::string file_name)
{
    std::fstream my_file;
    my_file.open(&file_name[0], std::ios::in);
    if (!my_file)
    {
        std::cout << "No such file" << std::endl;
        exit(1);
    }
    my_file.close();
}