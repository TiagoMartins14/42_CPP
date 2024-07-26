#pragma once
#include <string>
#include <iostream>
#include "A_Materia.hpp"
#include "I_Character.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_materia[4];

public:
	Character();
	Character(const std::string &name);
	Character(const Character &copy);
	Character &operator=(const Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};