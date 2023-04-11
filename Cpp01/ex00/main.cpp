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

/*
	Stack | Heap
Stack -> static hafızanın tahsisi (değişmeyen örn; referansın doğrudan değişimi)
Heap ->dinamik hafıza tahsisi

S -> değişkenlere doğrudan erişilir  -> bu yüzden daha hızlı erişim
H -> değişkenlere dolaylı yoldan erişim (örn; i1.isim)

S -> program complie-time bellek tahsisi gerçekleşir. (derlenme esnasında)
H -> program runtime esnasında bellek tahsisi. (çalışma esnasında)
*/