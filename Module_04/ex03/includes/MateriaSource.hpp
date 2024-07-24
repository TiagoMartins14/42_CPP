#include "I_MateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &copy);
	~MateriaSource() {}
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};