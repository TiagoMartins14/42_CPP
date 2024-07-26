#pragma once
#include "A_Materia.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &copy);
	~Ice();

	Ice *clone() const;
	void use(ICharacter &target);
};