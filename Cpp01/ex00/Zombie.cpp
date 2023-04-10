#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): name(name)
{
	std::cout << "Zombie created" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie deleted" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
