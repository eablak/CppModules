#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <forward_list>

template<class T>
void print_container(T &container)
{
  for(int i = 0;i < (int)container.size(); i++)
    std::cout << container[i] << std::endl;
}

template <typename T>
void printList(const std::list<T>& myList) {
    typename std::list<T>::const_iterator it;
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << std::endl;;
    }
    
}

template <typename T>
void printFlist(const std::forward_list<T>& myList) {
    typename std::forward_list<T>::const_iterator it;
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << "\n";
    }
}


int main()
{
  // 1) ARRAY

  std::cout << "ARRAY" << std::endl;
  std::array<int, 5> my_array = {47,76,43,65,13};

  int len = my_array.size();
  std::cout << "array size: " << len << std::endl;

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



  // // 3) DEQUE
  
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
  // std::list<int> my_list = {9,5,8,1,7,3}; -> c++11
  std::list<int> my_list;
  for(int i = 0;i < 5;i++)
    my_list.push_back(rand() % 10);
  my_list.pop_back();
  my_list.pop_back();
  my_list.sort();
  my_list.push_back(99);
  my_list.push_front(-99);

  printList(my_list);

  try{
    std::list<int>::iterator it = easyfind(my_list,7);
    std::cout << "value: " << *it << std::endl; }
  catch(const std::exception &e){
    std::cerr << e.what(); }



  // 5) FORWARD LIST

  std::cout << std::endl << std::endl << "FORWARD LIST" << std::endl;
  
  // std::forward_list<int> f_list = {-6,-6,-5,-4,-2}; -> std11
  std::forward_list<int> f_list;
  f_list.push_front(10);
  f_list.push_front(-100);
  f_list.reverse();
  f_list.unique();
  f_list.push_front(77);

  printFlist(f_list);


  try{
    std::forward_list<int>::iterator it = easyfind(f_list,-100);
    std::cout << "value: " << *it << std::endl; }
  catch(const std::exception &e){
    std::cerr << e.what(); } 
  return (1);
}