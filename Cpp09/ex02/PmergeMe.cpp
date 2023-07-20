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

template <class T>
void PmergeMe::InsertSort(T &container){
    int i,key=0,j=0;
    for(i = 1;i<(int)container.size();i++){
        key = container[i];
        j = i-1;
        while(j>=0 && container[j]>key){
            container[j+1] = container[j];
            j--;
        }
        container[j+1] = key;
    }
}

template <class T>
void PmergeMe::MergeInsertSort(T &container){
    if (container.size() <= 10){
        InsertSort(container);
        
    }
}

template <class T>
void PmergeMe::PrintContainer(T &container){
    for(int i = 0;i<(int)container.size();i++){
        std::cout << container[i] << " "; }
}

void PmergeMe::Process(int ac, char **av){
    std::cout << "Before: ";
    for (int i = 1;i<ac;i++)
        std::cout << av[i] << " ";
    std::cout << std::endl << "After: ";
    clock_t start_vector = clock();
    MergeInsertSort(my_vector);
    // MergeInsertSort(my_deque);
    clock_t end_vector = clock();
    PrintContainer(my_vector);
    // PrintContainer(my_deque);
    std::cout << std::endl;
    double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000;
    std::cout << time_vector << std::endl;
}
