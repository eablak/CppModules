#include <iostream>

class Contact
{
  public: //private // hiçbir şey yazmamak private demek
	std::string NAME;
	std::string SURNAME;
	std::string NICKNAME;
	std::string NUMBER;
	std::string DARKEST_SECRET;
};

int	main(void)
{
	Contact p1;
	p1.NAME = "esra";
	p1.SURNAME = "ablak";
	p1.NICKNAME = "eablak";
	p1.NUMBER = "777";
	p1.DARKEST_SECRET = "WBS";

	std::cout << "p1.adi: " << p1.NAME << std::endl;
	std::cout << "p1.soyadi: " << p1.SURNAME << std::endl;
	std::cout << "p1.nick: " << p1.NICKNAME << std::endl;
	std::cout << "p1.numb: " << p1.NUMBER << std::endl;
	std::cout << "p1.secret: " << p1.DARKEST_SECRET << std::endl;
	return (0);
}