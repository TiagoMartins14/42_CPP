#include "A_Materia.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice *clone() const;
	virtual void use(ICharacter &target);
	~Ice();
};