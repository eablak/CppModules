#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyB){ *this = copyB; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copyB) 
{
    this->lst = copyB.lst;
    this->res = copyB.res;
    this->map = copyB.map;
    return (*this);
}

void BitcoinExchange::CheckFile(std::string file_name)
{
    std::fstream my_file;
    my_file.open(&file_name[0], std::ios::in);
    if (my_file.is_open()){
        std::string line;
        bool is_empty = true;
        while(getline(my_file,line)){
            if (!line.empty()){
                is_empty = false;
                break;
            }
        }
        if (is_empty)
        {
            std::cout << "Error: file is empty" << std::endl;
            my_file.close();
            exit(1);    
        }
    }else{
        std::cout << "Error: No such file" << std::endl;
        my_file.close();
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
        data_file.close();
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
        if (start && line == "date | value")
        {
            start = false;
            continue;
        }
        std::size_t pos = line.find("|");
        if (pos > line.length())
            this->lst.push_back(std::make_pair("Error: ","bad input => "+line));
        else{
            try{
                float number = std::stof(line.substr(pos+1));

                if (number < 0)
                    this->lst.push_back(std::make_pair("Error: ","not a positive number."));
                else if (number > 1000)
                    this->lst.push_back(std::make_pair("Error: ","too large a number."));
                else 
                    this->lst.push_back(std::make_pair(line.substr(0,pos-1),line.substr(pos+1)));
                
            }
            catch(const std::exception &e){
                this->lst.push_back(std::make_pair("Error: ","bad input =>"+line.substr(pos+1)));
            }
        }
    }
    input_file.close();
}

int BitcoinExchange::CheckValidDate(std::list<std::pair<std::string, std::string> >::iterator it){

    if (it->first.length() != 10)
        return 0;
    std::string year,month,day,div,div_two;
    year = it->first.substr(0,4);
    month = it->first.substr(5,2);
    day = it->first.substr(8,2);
    div = it->first.substr(4,1);
    div_two = it->first.substr(7,1);
    
    if (div == "-" && div_two == "-"){
        try{
            
            int int_year = std::stoi(year);
            int int_month = std::stoi(month);
            int int_day = std::stoi(day);

            if (int_year < 2009 || int_year > 9999 || int_month < 1 || int_month > 12 || int_day < 1 || int_day > 31)
                return 0;

            if ((int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11) && int_day > 30)
                return 0;

            if (int_month == 2){
                if (int_month == 2) {
                    int max_day = 28;
                    if (int_year % 4 == 0)
                        max_day = 29;
                    if ((int_year % 100 == 0 && int_year % 400 != 0) || (int_year % 400 == 0 && int_year % 4000 == 0)) 
                        max_day = 28;
                    if (int_day > max_day)
                        return 0; }
            }

            return 1;
        }
        catch(const std::exception &e){
            return 0;
        }
    }
    return 0;
}

int BitcoinExchange::CheckValidValue(std::list<std::pair<std::string, std::string> >::iterator it) {
    for (std::string::const_iterator strIt = (it->second).begin(); strIt != (it->second).end(); ++strIt) {
        char c = *strIt;
        if (!std::isdigit(c) && (c != '-' && c != '.' && c != ' ')) {
            return 0;
        }
    }
    return 1;
}

int BitcoinExchange::CheckDateInt(std::list<std::pair<std::string, std::string> >::iterator it){
    for (std::string::const_iterator dateIt = (it->first).begin(); dateIt != (it->first).end(); ++dateIt) {
        char c = *dateIt;
        if (!std::isdigit(c) && c != '-' ) {
            return 0;
        }
    }
    return 1;    
}

void BitcoinExchange::GetExchange()
{
    std::list<std::pair<std::string, std::string> >::iterator it;
    std::map<std::string, float>::iterator ite;
    std::list<std::pair<std::string, std::string> >::iterator res;

    int match = false;
    for(it = lst.begin(); it != lst.end(); it++)
    {
        match = false;
        if (it->first != "Error: "){
            if (CheckValidDate(it) && CheckValidValue(it) && CheckDateInt(it))
            {
                for(ite = map.begin(); ite != map.end(); ite++){
                    if (it->first == ite->first)
                    {
                        match = true;
                        float nbr = ite->second * std::stof(it->second);
                        std::stringstream s;
                        s<<nbr;
                        std::string result = s.str();
                        this->res.push_back(std::make_pair(it->first + " =>" + it->second," = " + result));
                    }
                }
                if (match == false)
                    FindValue(it);      
            }
            else
                this->res.push_back(std::make_pair("Error: ","invalid date"));
        }
        else
            this->res.push_back(std::make_pair(it->first,it->second));
    }
}

void BitcoinExchange::FindValue(std::list<std::pair<std::string, std::string> >::iterator it)
{
    std::map<std::string, float>::iterator find = map.lower_bound(it->first);
    if (find->first != map.begin()->first)
        find--;
    float nbr = find->second * std::stof(it->second);
    std::stringstream s;
    s<<nbr;
    std::string result = s.str();
    this->res.push_back(std::make_pair(it->first + " =>" + it->second," = " + result));
}


void BitcoinExchange::GetResult()
{
    std::list<std::pair<std::string, std::string> >::iterator it;

    for(it = res.begin(); it != res.end(); it++)
        std::cout << it->first << it->second << std::endl;
}
