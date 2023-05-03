#include "Character.hpp"

Character::Character(std::string name):name(name) {
	for (int i = 0; 4 > i; ++i) {
		this->inventory[i] = NULL;
	}
	std::cout << "Character " << name << " is Created !" << std::endl;
}

Character::Character() {
	std::cout << "Character Created !" << std::endl;
}

Character::Character(Character &copy):name(copy.getName()) {
	for (int i = 0; i < 4; ++i) {
		this->inventory[i] = copy.inventory[i];
	}
	std::cout << "Character Copied !" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
	if(this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	std::cout << "Character Destructed !" << std::endl;
}

Character &Character::operator=(const Character &c) {
	for (int i = 0; i < 4; ++i) {
		if(this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = c.inventory[i]->clone();
	}
	return *this;
}
std::string const &Character::getName()const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    if(!m)
    {
        for(int i = 0;i < 4;i++)
        {
            if (!this->inventory[i])
            {
                this->inventory[i] = m;
                break;
            }
        }
    }
    else
        std::cout << "m is empty" << std::endl;
}

void Character::unequip(int idx)
{
    if (this->inventory[idx] != NULL && (idx >= 0 && idx <= 3))
        this->inventory[idx] = 0;
    else
        std::cout << "inventory is already null or wrong idx" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if ((idx <= 3 && idx >= 0)&& this->inventory[idx])
        this->inventory[idx]->use(target);
}