#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &copyP){ *this = copyP; }
PmergeMe &PmergeMe::operator=(const PmergeMe &copyP){
    this->my_deque = copyP.my_deque;
    this->my_vector = copyP.my_vector;
    return (*this);
}
PmergeMe::~PmergeMe(){}


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
void PmergeMe::MergeInsertSort(T &container, size_t treshold){
    if (container.size() <= treshold){
        InsertSort(container);
        return ;
    }
    
    typename T::iterator begin = container.begin();
    typename T::iterator mid = container.begin() + (container.end() - container.begin()) / 2;
    typename T::iterator end = container.end();

    T left_subcontainer(begin,mid);
    T right_subcontainer(mid,end);

    MergeInsertSort(left_subcontainer,treshold);
    MergeInsertSort(right_subcontainer,treshold);
    std::merge(left_subcontainer.begin(),left_subcontainer.end(),
                right_subcontainer.begin(),right_subcontainer.end(),container.begin());
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
    MergeInsertSort(my_vector,10);
    clock_t end_vector = clock();
    PrintContainer(my_vector);
    double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000;
    std::cout << std::endl << "Time to process a range of " << my_vector.size() << " elements with std::vector " << time_vector << " us" << std::endl;
    
    clock_t start_deque = clock();
    MergeInsertSort(my_deque,10);
    clock_t end_deque = clock();
    double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << my_deque.size() << " elements with std::deque " << time_deque << " us";
}
