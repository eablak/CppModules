#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &r)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->name = r.name;
    this->hit_points = r.hit_points;
    this->energy_points = r.energy_points;
    this->attack_damage = r.attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &r)
{
    std::cout << "FragTrap copy assignment constructor called" << std::endl;
    this->name = r.name;
    this->hit_points = r.hit_points;
    this->energy_points = r.energy_points;
    this->attack_damage = r.attack_damage;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->name << " says high five buddy!" << std::endl;
}