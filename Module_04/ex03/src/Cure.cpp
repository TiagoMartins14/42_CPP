#include "../includes/Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}