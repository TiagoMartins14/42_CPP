#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (std::string target)
	: AForm ("PresidentialPardonForm", 25, 5), _target (target)
{
}

PresidentialPardonForm::PresidentialPardonForm (
	const PresidentialPardonForm &other)
	: AForm (other), _target (other._target)
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator= (const PresidentialPardonForm &copy)
{
	this->_target = copy._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () {}

void
PresidentialPardonForm::executePardon () const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!"
			  << std::endl;
}
