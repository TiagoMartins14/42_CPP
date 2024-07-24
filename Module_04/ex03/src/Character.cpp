#include "../includes/Character.hpp"

Character::Character()
{
	_name = "Default character";

	for (int idx = 0; idx < 4; idx++)
		_materia[idx] = NULL;
}
Character::Character(const std::string &name) : _name(name)
{
	for (int idx = 0; idx < 4; idx++)
		_materia[idx] = NULL;
};

Character::Character(const Character &copy)
{
	for (int idx = 0; idx < 4; idx++)
		_materia[idx] = NULL;

	*this = copy;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int idx = 0; idx < 4; idx++)
		{
			if (this->_materia[idx])
				delete this->_materia[idx];
			if (other._materia[idx])
				this->_materia[idx] = other._materia[idx]->clone();
			else
				this->_materia[idx] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	int idx = 0;

	while (idx != NULL && idx < 4)
		idx++;
	if (idx < 4)
		this->_materia[idx] = m;
	else
		std::cout << "Unable to add item. Inventory full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->_materia[idx] = NULL;
}

void Character::use(int idx, Character &target)
{
	if (idx < 0 || idx > 3)
		return;
	if (this->_materia[idx])
		this->_materia[idx]->use(target);
	else
		std::cout << "There is nothing to be used in this slot." << std::endl;
}