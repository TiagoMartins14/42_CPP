#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  public:
	PresidentialPardonForm (std::string target);
	PresidentialPardonForm (const PresidentialPardonForm &other);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &copy);
	~PresidentialPardonForm ();

	void executePardon () const;
};