#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &r):AMateria(r)
{
    std::cout << "Cure copy called" << std::endl;
    *this = r;
}

Cure &Cure::operator=(const Cure &r)
{
    std::cout << "Cure operator called" << std::endl;
    this->AMateria::operator=(r);
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Destructor called" << std::endl;
}

AMateria *Cure::clone()const
{
    return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << "heals " << target.getName() << " Wounds" << std::endl;
}