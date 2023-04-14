#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name,Weapon &weapon):weapon(weapon), name(name)
{
}

HumanA::~HumanA()
{
    return ;
}

void HumanA::attack()
{
    std::string str = this->weapon.getType();
    std::cout << this->name << " attacks with their " << str << std::endl;
}
