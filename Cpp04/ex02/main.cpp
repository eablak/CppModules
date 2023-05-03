#include <iostream>
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
   const Animal* animal[4] = {new Dog(),new Cat(),new Dog(), new Cat()};

	for (int i = 0; i < 4; i++) {
		animal[i]->makeSound();
		delete animal[i];
	}
    return 0;
}
