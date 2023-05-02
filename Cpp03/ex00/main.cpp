#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap usr1("esra");
    ClapTrap usr2("rabia");
    ClapTrap usr3("nuray");    

    usr1.attack("rabia");
    usr2.takeDamage(4);
    usr2.attack("nuray");
    usr3.takeDamage(6);
    usr2.attack("esra");
    usr1.takeDamage(8);
    usr3.beRepaired(3);
    usr3.attack("esra");
    usr1.takeDamage(5);
    usr2.attack("esra");
    usr1.takeDamage(3);
}