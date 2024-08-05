#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm ();
	ShrubberyCreationForm (const std::string &target);
	ShrubberyCreationForm (const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm ();

	void createForm (void) const;
};
