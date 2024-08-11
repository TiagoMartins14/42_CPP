#pragma once
#include "AForm.hpp"
#include "PardonRequestForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
  public:
	// Constructors and destructor
	Intern ();
	Intern (const Intern &other);
	~Intern ();

	// Overload
	Intern &operator= (const Intern &copy);

	// Member function
	AForm *makeForm (std::string &form, std::string &target);
};
