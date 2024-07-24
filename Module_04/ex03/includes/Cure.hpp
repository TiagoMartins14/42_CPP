#pragma once
#include "A_Materia.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);
	virtual ~Cure();
};