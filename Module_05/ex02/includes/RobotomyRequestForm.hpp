#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm (std::string target);
	RobotomyRequestForm (const RobotomyRequestForm &other);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &copy);
	~RobotomyRequestForm ();

	void executeRobotomy () const;
};
