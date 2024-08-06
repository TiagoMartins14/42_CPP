#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm (std::string _target);
	RobotomyRequestForm (const RobotomyRequestForm &other);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &copy);
	~RobotomyRequestForm ();

	void executeRobotomy () const;
};
