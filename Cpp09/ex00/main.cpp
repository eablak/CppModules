#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    // data.csv , parse
    // input file check (|, date, valid value)
    // input file tarihi data.csv'de bul ve işle 

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

}