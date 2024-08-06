#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	PresidentialPardonForm ();
	PresidentialPardonForm (const PresidentialPardonForm &other);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &copy);
	~PresidentialPardonForm ();

	void executePardon () const;
};
