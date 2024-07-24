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