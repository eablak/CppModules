#include <iostream>
#include "ScavTrap.hpp"

int main()
{
    ScavTrap usr1("esra");
    ScavTrap usr2("rabia");
    ScavTrap usr3("nuray");   

    usr1.attack("rabia");
    usr2.takeDamage(50);
    usr2.attack("nuray");
    usr3.takeDamage(30);
    usr2.attack("esra");
    usr1.takeDamage(20);
    usr3.beRepaired(30);
    usr3.attack("esra");
    usr1.takeDamage(75);
    usr2.attack("esra");
    usr1.takeDamage(10);
    usr1.guardGate();
     }