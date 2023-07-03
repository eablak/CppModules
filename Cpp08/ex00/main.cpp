#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

//!!!!makefile std11

template<class T>
void print_container(T &container)
{
  for(int i = 0;i < (int)container.size(); i++)
    std::cout << container[i] << std::endl;
}

template<class T>
void for_list(T &container)
{
  for(auto number : container)
    std::cout << number << std::endl;
}

template<class T>
void foreach_list(T &container)
{
  std::for_each(container.begin(), container.end(), [](const int n){ std::cout << n << " ";});
  std::cout << "\n";
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



  // 4) LIST

  std::cout << std::endl << std::endl << "LIST" << std::endl;

  std::list<int> my_list = {9,5,8,1,7,3};
  my_list.pop_back();
  my_list.pop_back();
  my_list.sort();
  my_list.push_back(99);
  my_list.push_front(-99);

  for_list(my_list);
  foreach_list(my_list);

  try{
    std::list<int>::iterator it = easyfind(my_list,7);
    std::cout << "value: " << *it << std::endl; }
  catch(const std::exception &e){
    std::cerr << e.what(); }



  // 5) FORWARD LIST

  std::cout << std::endl << std::endl << "FORWARD LIST" << std::endl;
  
  std::forward_list<int> f_list = {-6,-6,-5,-4,-2};
  f_list.push_front(-100);
  f_list.reverse();
  f_list.unique();
  f_list.push_front(77);

  for_list(f_list);
  foreach_list(f_list);

  try{
    std::forward_list<int>::iterator it = easyfind(f_list,-100);
    std::cout << "value: " << *it << std::endl; }
  catch(const std::exception &e){
    std::cerr << e.what(); } 
}