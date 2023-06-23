#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>

//!!!!makefile std11

template<class T>
void print_container(T &container)
{
  for(int i = 0;i < (int)container.size(); i++)
    std::cout << container[i] << std::endl;
}

int main()
{
  // 1) ARRAY
  std::cout << "ARRAY" << std::endl;
  std::array<int, 5> my_array = {47,76,43,65,13};

  int len = my_array.size();
  std::cout << "array size: " << len << std::endl;

  int *begin = my_array.begin();
  int *end = my_array.end();
  std::cout << "begin: " << (begin)[0] << std::endl;
  // std::cout << "end: " << (end )[0] << std::endl; // 0
  // std::cout << "end: " << (end - 4)[0] << std::endl; // 76
  std::cout << "end: " << (end - 4)[3] << std::endl;
  // std::cout << "end: " << (end - 4)[4] << std::endl; // 0

  try{
    std::array<int ,5>::iterator it = easyfind(my_array,10);
    std::cout << "value: " << *it << std::endl;} 
  catch (const std::exception &e){ 
    std::cerr << e.what();
  }

  std::cout << std::endl;
  my_array.fill(10);
  // print_container(my_array);

  try{
    std::array<int ,5>::iterator it = easyfind(my_array,10);
    std::cout << "value: " << *it << std::endl;} 
  catch (const std::exception &e){ 
    std::cerr << e.what();
  }


  // 2) VECTOR

  std::cout << std::endl << std::endl << "VECTOR" << std::endl;

  std::vector<int> my_vector;
  my_vector.push_back(1);
  my_vector.push_back(2);
  my_vector.push_back(3);
  print_container(my_vector);

  try{
    std::vector<int>::iterator it = easyfind(my_vector,2);
    std::cout << "value: " << *it << std::endl; }
  catch(const std::exception &e){
    std::cerr << e.what(); }



  // 3) DEQUE
  
  std::cout << std::endl << std::endl << "DEQUE" << std::endl;
  
  std::deque<int> my_deque;
  my_deque.push_back(10);
  my_deque.push_front(7);
  my_deque.push_back(15);
  print_container(my_deque);

  try{
    std::deque<int>::iterator it = easyfind(my_deque,50);
    std::cout << "value" << *it << std::endl; }
  catch (const std::exception &e){
    std::cerr << e.what(); }
}