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

template <class T>
void AssignmentContainers(int ac,char **av,T &container){
    for(int i = 1;i<ac;i++){
        std::string str = av[i];
        int nbr = std::stoi(str);
        container.push_back(nbr);
    }
}

void PmergeMe::FillContainers(int ac,char **av){
    AssignmentContainers(ac,av,my_vector);
    AssignmentContainers(ac,av,my_deque);
}

