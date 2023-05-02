#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name("ClapTrap"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Constructor called" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &r)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = r;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &r)
{
    std::cout << "Copy assignment constructor called" << std::endl;
    this->name = r.name;
    this->hit_points = r.hit_points;
    this->energy_points = r.energy_points;
    this->attack_damage = r.attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points <= 0 || this->hit_points <= 0)
	{
		std::cout << "No energy or hit points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target 
    << ",causing " << this->attack_damage << " points of damage " << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0 || this->energy_points <= 0)
	{
		std::cout << "No health or hit points already dead" << std::endl;
		return ;
	}
	else if ((int)amount > this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount << " damage and died" << std::endl;
		this->hit_points -= amount;
	}
	else
	{
		this->hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " damage and " << this->hit_points
		<< " hit points remaining" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0 || this->energy_points <= 0)
	{
		std::cout << "No health or hit points already dead" << std::endl;
		return ;
	}
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " repaired and " << this->name << " has "
	<< this->hit_points << " hit points" << std::endl;
	this->energy_points--;
}