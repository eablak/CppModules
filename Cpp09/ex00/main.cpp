#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Arg error" << std::endl;
        exit(1);
    }

    BitcoinExchange btc;
    btc.CheckFile(av[1]);
}