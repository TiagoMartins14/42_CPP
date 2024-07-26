#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
		this->_materias[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int idx = 0; idx < 4; idx++)
		{
			if (this->_materias[idx])
				delete this->_materias[idx];
			if (copy._materias[idx])
				this->_materias[idx] = copy._materias[idx]->clone();
			else
				this->_materias[idx] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_materias[idx])
			delete this->_materias[idx];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	int idx = 0;

	while (this->_materias[idx] && idx < 4)
		idx++;
	if (idx < 4)
		this->_materias[idx] = materia;
	else
		std::cout << "No space left to learn a new materia!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int idx = 0;
	while (idx < 4 && this->_materias[idx] && this->_materias[idx]->getType() != type)
		idx++;
	if (idx == 4)
	{
		std::cout << "Unable to create Materia. Type not learnt." << std::endl;
		return NULL;
	}
	return this->_materias[idx]->clone();
}