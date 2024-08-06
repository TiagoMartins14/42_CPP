#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (std::string target)
	: AForm ("RobotomyRequestForm", 72, 45), _target (target)
{
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &other)
	: AForm (other), _target (other._target)
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator= (const RobotomyRequestForm &copy)
{
	this->_target = copy._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm () {}

void
RobotomyRequestForm::executeRobotomy () const
{
	std::cout << "[Drilling noises]" << std::endl << std::endl;

	srand (static_cast<unsigned int> (time (0)));

	int randomNumber = rand () % 2;

	if (randomNumber == 0)
		{
			std::cout << _target << " has been robotomized!" << std::endl;
		}
	else
		std::cout << _target << " failed to be robotomized!" << std::endl;
}
