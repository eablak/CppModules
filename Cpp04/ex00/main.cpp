#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!s
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    const WrongAnimal *wa = new WrongAnimal();
    const WrongAnimal *wc = new WrongCat();
    wa->makeSound();
    wc->makeSound();
    delete wc;
    delete wa;
    return 0;
}
