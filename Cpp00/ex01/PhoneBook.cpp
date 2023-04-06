#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
	std::cout << "Phonebook Created !" << std::endl;
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook Destroyed !" << std::endl;
}

std::string add_contact_utils(std::string comment, std::string str)
{
	std::cout << "Enter " << comment;
	std::getline(std::cin, str);
	while (str == "\0")
	{
		std::cout << "Error please not type null charachter" << std::endl;
		std::cout << comment;
		std::getline(std::cin, str);
	}
	return (str);
}

void PhoneBook::add_contact()
{
	std::string str;
	str = add_contact_utils("First Name: ", str);
	this->contacts[this->index % 8].set_firstname(str);
	str = add_contact_utils("Last Name: ", str);
	this->contacts[this->index % 8].set_lastname(str);
	str = add_contact_utils("Phone Number: ", str);
	this->contacts[this->index % 8].set_phonenumber(str);
	str = add_contact_utils("Nick Name: ", str);
	this->contacts[this->index % 8].set_nickname(str);
	str = add_contact_utils("Darkest Secret: ", str);
	this->contacts[this->index % 8].set_secret(str);
	this->index++;
}

std::string truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
// void Contact:: ?

void PhoneBook::search_contact()
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname"
				<< "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; (i < this->index && i < 8); i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_firstname());
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_lastname());
		std::cout << "|" << std::setw(10) << truncate(this->contacts[i].get_nickname()) << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

	int number;
	if (this->index > 0)
	{
		while (1)
		{
			std::cout << "Enter an index: ";
			std::cin >> number;
			if (number > this->index || number > 7 || index < 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
								'\n');
				std::cout << "Invalid input" << std::endl;
			}
			else
			{
				this->contacts[number].print_contact();
				break ;
			}
		}
	}
}