#pragma once
#include "A_Materia.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &other);
	~Cure();

	Cure *clone() const;
	void use(ICharacter &target);
};