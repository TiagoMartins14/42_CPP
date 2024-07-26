#include "A_Materia.hpp"

AMateria::AMateria()
{
	_type = "not defined";
}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}