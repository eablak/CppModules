#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Created" << std::endl;
}

AMateria::AMateria(const AMateria &r)
{
    *this = r;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructed called" << std::endl;
}

AMateria::AMateria(std::string const & type):type(type)
{
    std::cout << "Abstract materia is created" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "A materia is used on " << target.getName() << std::endl;
}
