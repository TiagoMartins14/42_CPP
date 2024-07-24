#include "A_Materia.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &copy);
	Ice *clone() const;
	virtual void use(ICharacter &target);
	~Ice();
};