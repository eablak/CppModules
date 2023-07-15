#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyB){ *this = copyB; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copyB) 
{(void) copyB; return (*this);} // !

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

void BitcoinExchange::parse_datacsv(const std::string file)
{
    std::fstream data_file;
    data_file.open(&file[0], std::ios::in);
    if(!data_file)
    {
        std::cout << "No such file" << std::endl;
        exit(1);
    }
    int start = true;
    std::string line = "";
    while(getline(data_file,line))
    {
        if (start)
        {
            start = false;
            continue;
        }
        std::string a = ",";
        std::size_t pos = line.find(",");
        this->map.insert(std::make_pair(line.substr(0,pos),(line.substr(pos).length())));
    }
    data_file.close();

    std::map<std::string, float>::iterator it;
    for(it=map.begin();it!=map.end();it++)
        std::cout << "first: " <<  it->first << " second:" << it->second << std::endl;
}