#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::get_firstname()
{
	return (this->first_name);
}

std::string Contact::get_lastname()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nick_name);
}

std::string Contact::get_phonenumber()
{
	return (this->phone_number);
}

std::string Contact::get_secret()
{
	return (this->darkest_secret);
}

void Contact::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::set_nickname(std::string nick_name)
{
	this->nick_name = nick_name;
}

void Contact::set_phonenumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

void Contact::print_contact()
{
	std::cout << "First Name: " << this->get_firstname() << std::endl;
	std::cout << "Last Name: " << this->get_lastname() << std::endl;
	std::cout << "Phone number : " << this->get_phonenumber() << std::endl;
	std::cout << "Nickname : " << this->get_nickname() << std::endl;
	std::cout << "Secret : " << this->get_secret() << std::endl;
}