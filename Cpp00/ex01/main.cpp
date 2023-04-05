#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;

	/*
    C++ dinamik bellek kullanımı
    Program çalışırken dinamik olarak bellek tahsisi heap adı verilen bellek bölgesinden yapılır.
    C++'da dinamik bellek işlemleri için new ve delete işlemcileri kullanılır.
    new işlemcisi bellek tahsisi yapar ve tahsis edilen belleğin başlangıç adresini geri döndürür.
    delete işlemcisi daha önce new işlemcisi ile tahsis edilen belleği boşaltır.
    */
	std::cout << std::endl << " -ADD: add a contact to the phonebook" << std::endl;
	std::cout << " -SEARCH: search for a contact in the phonebook" << std::endl;
	std::cout << " -EXIT: quit the program" << std::endl;
	std::string str;
	while (1)
	{
		std::cout << "Enter Command: ";
		std::getline(std::cin, str);
		if (str == "EXIT")
			return (0);
		if (str == "ADD")
			phonebook.add_contact();
		else if (str == "SEARCH")
			phonebook.search_contact();
	}
}
