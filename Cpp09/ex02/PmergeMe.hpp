#ifndef PMERGEME_HP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{

    std::vector<int>my_vector;
    std::deque<int>my_deque;

    public:

    int PmergeMeCheck(int ac, char **av);
    void FillContainers(int ac,char **av);
};



#endif