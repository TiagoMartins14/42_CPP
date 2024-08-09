#pragma once
#include "Form.hpp"
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
	Form *makeForm (std::string &form, std::string &target);
};
