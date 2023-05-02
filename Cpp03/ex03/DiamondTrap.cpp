#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::string name = "DiamondTrap";
    ClapTrap::name = name + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &r)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = r;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &r)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    ClapTrap::name = r.name + "_clap_name";
	ScavTrap::name = r.name;
	FragTrap::name = r.name;
	name = r.name;
	this->hit_points = r.hit_points;
	this->energy_points = r.energy_points;
	this->attack_damage = r.attack_damage;
    return (*this);
};

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
};

void DiamondTrap::attack(std::string const & target)
{
    this->ScavTrap::attack(target);
};

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << this->name 
    << " ClapTrap name is " << this->ClapTrap::name << std::endl;
};