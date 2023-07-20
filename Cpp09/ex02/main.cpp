#include "PmergeMe.hpp"

void myError(){
    std::cout << "Error" << std::endl;
    exit(1);
}

int main(int ac, char *av[]){

    if (!(ac > 1))
        myError();

    PmergeMe pmergeme;
    if (pmergeme.PmergeMeCheck(ac,av)==0)
        myError();
    pmergeme.FillContainers(ac,av);
}