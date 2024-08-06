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

	const std::string &getTarget () const;

	void executeForm () const;

	static int const signGrade = 72;
	static int const executeGrade = 45;
};
