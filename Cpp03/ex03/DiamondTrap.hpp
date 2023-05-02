#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
    std::string name;
    
    public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &copy);
    ~DiamondTrap();

    void attack(std::string const &target);
    void whoAmI();
};

#endif