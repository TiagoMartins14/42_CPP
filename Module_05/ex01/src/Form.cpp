#include "Form.hpp"

Form::Form (const std::string name, const int gradeToSign,
			const int gradeToExecute)
	: _name (name), _gradeToSign (gradeToSign),
	  _gradeToExecute (gradeToExecute), _signed (false)
{
}

Form::Form (const Form &other)
	: _name (other._name), _gradeToSign (other._gradeToSign),
	  _gradeToExecute (other._gradeToExecute), _signed (other._signed)
{
}

Form::~Form () {}

Form &
Form::operator= (const Form &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

const std::string
Form::getName ()
{
	return _name;
}

int
Form::getGradeToSign ()
{
	return _gradeToSign;
}

int
Form::getGradeToExecute ()
{
	return _gradeToExecute;
}

bool
Form::getSigned ()
{
	return _signed;
}

void
Form::beSigned (Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade () <= this->getGradeToSign ())
		this->_signed = true;
	else
		GradeTooLowException ();
}

const char *
Form::GradeTooHighException::what () const throw ()
{
	return "Grade too high";
}

const char *
Form::GradeTooLowException::what () const throw ()
{
	return "Grade too low";
}
