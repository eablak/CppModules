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
        this->map.insert(std::make_pair(line.substr(0,pos),std::stof(line.substr(pos+1))));
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
            this->lst.push_back(std::make_pair("Error: ","bad input => " + line));
        else{
            long int number = std::stof(line.substr(pos+1));
            if (number < 0)
                this->lst.push_back(std::make_pair("Error: ","not a positive number."));
            else if (number > INT_MAX)
                this->lst.push_back(std::make_pair("Error: ","too large a number."));
            else
                this->lst.push_back(std::make_pair(line.substr(0,pos-1),line.substr(pos+1)));
        }
    }
    input_file.close();

}

void BitcoinExchange::GetExchange()
{
    std::list<std::pair<std::string, std::string>>::iterator it;
    std::map<std::string, float>::iterator ite;
    std::list<std::pair<std::string, std::string>>::iterator res;

    int match = false;
    for(it = lst.begin(); it != lst.end(); it++)
    {
        if (it->first != "Error: "){
            for(ite = map.begin(); ite != map.end(); ite++){
                if (it->first == ite->first)
                {
                    match = true;
                    float nbr = ite->second * std::stoi(it->second);
                    std::stringstream s;
                    s<<nbr;
                    std::string result = s.str();
                    this->res.push_back(std::make_pair(it->first + " =>" + it->second," = " + result));
                }
            }
            if (match == false)
            {
                std::cout << "islem " <<std::endl;
            }
        }
        else
            this->res.push_back(std::make_pair(it->first,it->second));
    }
}
//T_DATE!!!!
void BitcoinExchange::GetResult()
{
    std::list<std::pair<std::string, std::string>>::iterator it;

    for(it = res.begin(); it != res.end(); it++)
        std::cout << it->first << it->second << std::endl;
}