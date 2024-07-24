#include "../includes/A_Materia.hpp"

AMateria::AMateria()
{
	_type = "not defined";
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* " << _type << " was used on " << target.getName() << " *" << std::endl;
}