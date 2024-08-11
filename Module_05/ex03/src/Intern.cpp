#include "Intern.hpp"

Intern::Intern (const Intern &other) { *this = other; }

Intern &
Intern::operator= (const Intern &copy)
{
	(void)copy;
	return *this;
}

AForm *
Intern::makeForm (std::string &form, std::string &target)
{
}
