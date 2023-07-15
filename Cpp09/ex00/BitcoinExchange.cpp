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

void BitcoinExchange::ParseDatacsv(const std::string file)
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
        std::size_t pos = line.find(",");
        this->map.insert(std::make_pair(line.substr(0,pos),(line.substr(pos).length())));
    }
    data_file.close();
}

void BitcoinExchange::HandleInputFile(std::string file){
    
    std::fstream input_file;
    input_file.open(&file[0],std::ios::in);
    std::string line = "";
    int start = true;
    while(getline(input_file,line))
    {
        if (start)
        {
            start = false;
            continue;
        }
        std::size_t pos = line.find("|");
        if (pos > line.length())
            this->lst.push_back(std::make_pair(line," "));
        else
            this->lst.push_back(std::make_pair(line.substr(0,pos),line.substr(pos)));
    }
    input_file.close();

}

void BitcoinExchange::getExchange()
{
    std::list<std::pair<std::string, std::string>>::iterator it;
    for(it = lst.begin(); it != lst.end(); it++)
    {
        std::cout <<  it->first << it->second << std::endl;
    }
}