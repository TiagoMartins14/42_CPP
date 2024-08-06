#include "AForm.hpp"

AForm::AForm ()
	: _name ("no name"), _gradeToSign (1), _gradeToExecute (1), _signed (false)
{
}

AForm::AForm (const std::string name, const int gradeToSign,
			  const int gradeToExecute)
	: _name (name), _gradeToSign (gradeToSign),
	  _gradeToExecute (gradeToExecute), _signed (false)
{
}

AForm::AForm (const AForm &other)
	: _name (other._name), _gradeToSign (other._gradeToSign),
	  _gradeToExecute (other._gradeToExecute), _signed (other._signed)
{
}

AForm::~AForm () {}

AForm &
AForm::operator= (const AForm &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

const std::string
AForm::getName ()
{
	return _name;
}

int
AForm::getGradeToSign ()
{
	return _gradeToSign;
}

int
AForm::getGradeToExecute ()
{
	return _gradeToExecute;
}

bool
AForm::getSigned ()
{
	return _signed;
}

void
AForm::beSigned (Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade () <= this->getGradeToSign ())
		this->_signed = true;
	else
		GradeTooLowException ();
}

const char *
AForm::GradeTooHighException::what () const throw ()
{
	return "Grade too high";
}

const char *
AForm::GradeTooLowException::what () const throw ()
{
	return "Grade too low";
}
