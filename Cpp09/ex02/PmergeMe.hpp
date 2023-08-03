#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe{

    std::vector<int>my_vector;
    std::deque<int>my_deque;

    public:

    int PmergeMeCheck(int ac, char **av);
    void FillContainers(int ac,char **av);
    void Process(int ac,char **av);
    template <class T>
    void MergeInsertSort(T &container, size_t treshold);
    template <class T>
    void InsertSort(T &container);
    template <class T>
    void PrintContainer(T &container);

    PmergeMe();
    PmergeMe(const PmergeMe &copyM);
    PmergeMe &operator=(const PmergeMe &copyM);
    ~PmergeMe();
};



#endif