#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (const std::string &target)
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
PresidentialPardonForm::executeAction () const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!"
			  << std::endl;
}

const std::string &
PresidentialPardonForm::getTarget () const
{
	return _target;
}
