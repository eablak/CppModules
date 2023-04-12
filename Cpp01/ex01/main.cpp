#include "Zombie.hpp"

int	main(void)
{
    int N = 5;
	Zombie *zombiearray = zombieHorde(N, "zz");
	for (int i = 0; i < N; i++)
	{
		zombiearray[i].announce();
	}
	delete[] zombiearray;
}