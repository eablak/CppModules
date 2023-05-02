#include "ScavTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &r):ClapTrap("DefaultClap")
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->name = r.name;
    this->hit_points = r.hit_points;
    this->energy_points = r.energy_points;
    this->attack_damage = r.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &r)
{
    std::cout << "ScavTrap copy assignment constructor called" << std::endl;
    ClapTrap::operator= (r);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy_points <= 0 || this->hit_points <= 0)
    {
        std::cout << "No energy" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " 
    << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
    this->energy_points--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap Guard Gate!" << std::endl;
}