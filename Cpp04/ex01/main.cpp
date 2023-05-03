#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    
    const Animal *animals[4] = {new Cat(), new Dog(), new Cat(), new Dog()};
    for(int i = 0;i< 4;i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    return 0;
}
