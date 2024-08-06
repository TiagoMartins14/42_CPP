#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (const std::string &target)
	: AForm ("ShrubberyCreationForm", 145, 137), _target (target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm (
	const ShrubberyCreationForm &other)
	: AForm (other), _target (other._target)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator= (const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}

~ShrubberyCreationForm::ShrubberyCreationForm () {}

void
ShrubberyCreationForm::createForm ()
{
}
