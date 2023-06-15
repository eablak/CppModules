#include "iter.hpp"

template <typename T>
void printArray(T element)
{
    std::cout << element << std::endl;
}   


int main()
{
    int Array[] = {54,76,874,345,234};
    iter<int>(Array,5,printArray);
    std::cout << std::endl;
    ::iter(Array,5,printArray);

    std::cout << std::endl;

    std::string array[] =  {"esra","ablak","eablak"};
    int len = sizeof(array)/sizeof(std::string);
    ::iter(array,len,printArray);
}