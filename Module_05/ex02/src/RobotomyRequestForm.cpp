#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (const std::string &target)
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
RobotomyRequestForm::executeAction () const
{
	std::cout << "[Drilling noises]" << std::endl;

	srand (static_cast<unsigned int> (time (0)));

	int randomNumber = rand () % 2;

	if (randomNumber == 0)
		{
			std::cout << _target << " has been robotomized!" << std::endl;
		}
	else
		std::cout << _target << " failed to be robotomized!" << std::endl;
}

const std::string &
RobotomyRequestForm::getTarget () const
{
	return _target;
}
