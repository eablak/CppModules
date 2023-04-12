#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie deleted" << std::endl;
	return ;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":"
				<< " BraiiiiiiinnnzzzZ..." << std::endl;
}
