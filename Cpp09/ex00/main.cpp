#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }

    BitcoinExchange btc;
    btc.CheckFile(av[1]);
    btc.ParseDatacsv("data.csv");
    btc.HandleInputFile(av[1]);
    btc.GetExchange();
    btc.GetResult();

    std::cout<<std::endl;

    BitcoinExchange btc2;
    btc2.CheckFile("input2.txt");
    btc2.ParseDatacsv("data.csv");
    btc2.HandleInputFile("input2.txt");
    btc2.GetExchange();
    btc2.GetResult();

    std::cout<<std::endl;

    btc = btc2;
    btc.GetResult();
}