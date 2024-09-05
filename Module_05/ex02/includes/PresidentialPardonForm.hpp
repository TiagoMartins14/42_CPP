#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  public:
	PresidentialPardonForm (const std::string &target);
	PresidentialPardonForm (const PresidentialPardonForm &other);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &copy);
	~PresidentialPardonForm ();

	void executePardon () const;

	const std::string &getTarget () const;

	void executeAction () const;

	static int const signGrade = 25;
	static int const executeGrade = 5;
};
