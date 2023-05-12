#include "Zombie.hpp"

int	main(void)
{
	
	Zombie zombie("Zombie1");
	Zombie *zombie2 = newZombie("zombie2");
	zombie.announce();
	zombie2->announce();
	randomChump("zombie3");
	delete zombie2;

}