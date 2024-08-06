#pragma once
#include "AForm.hpp"
#include <fstream>
#include <sys/stat.h>

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm (const std::string &target);
	ShrubberyCreationForm (const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm ();

	const std::string &getTarget () const;

	void executeForm () const;

	static int const signGrade = 145;
	static int const executeGrade = 137;
};
