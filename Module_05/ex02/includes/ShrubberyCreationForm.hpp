#pragma once
#include "AForm.hpp"
#include <fstream>
#include <sys/stat.h>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm (const std::string &target);
	ShrubberyCreationForm (const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm ();

	void createForm () const;
};
