#include "PmergeMe.hpp"

int PmergeMe::PmergeMeCheck(int ac, char **av){

    for(int i=1;i<ac;i++){
        std::string str = av[i];
        char* end;
        long int result = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0')
            return 0;
        if (result <= 0)
            return 0;
    }
    return 1;
}