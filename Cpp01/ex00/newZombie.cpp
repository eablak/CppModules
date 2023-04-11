#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
	// pointer kullanıyoruz(new) heap
}

/*
	Heap
-> Objeleri depolamayı sağlayan alan.
-> Objenin başlangıç adresi stack'te, objelerin değerleri heap'te depolanır.
-> Heap'in boyutu dinamik olarak değişir. sabit değildir.
-> Stack'e göre daha yavaş objelere ulaşılır.

	Heap Area
	1)old space => eski objelerden kalan alan
	2)young space => aktif olarak kullanılan alan
Garabage Collection ile old space'deki objeleri FIFO mantığı ile free yapar.

class Insan{
	isim
	yas}
Insan i1 = new Insan()

i1 => stack'te (i1 objesinin referansı tutulur)
i1 için isim, yas => heap'te (asıl değerlerin tutulduğu alan)

stack	heap
_____	____

i1		isim
		yas

i1 ile başlangıçtaki değerin adresini tutarsın - i1.isim
*/