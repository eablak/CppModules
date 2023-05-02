#include <iostream>
#include "FragTrap.hpp"

int main()
{
    FragTrap usr1("esra");
    FragTrap usr2("rabia");
    FragTrap usr3("nuray");   

    usr1.attack("rabia");
    usr2.takeDamage(50);
    usr2.attack("nuray");
    usr3.takeDamage(80);
    usr2.attack("esra");
    usr1.takeDamage(30);
    usr3.beRepaired(20);
    usr3.attack("esra");
    usr1.takeDamage(40);
    usr2.attack("nuray");
    usr3.takeDamage(70);
    usr1.attack("nuray");
    usr3.takeDamage(10);
    usr1.highFivesGuys();
}