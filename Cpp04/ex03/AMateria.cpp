#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria is created" << std::endl;
    this->type = type;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "A materia is used on " << target.getName() << std::endl;
}
