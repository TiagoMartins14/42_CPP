#include "Form.hpp"

Form::Form (const std::string name, const int gradeToSign,
			const int gradeToExecute)
	: _name (name), _gradeToSign (gradeToSign),
	  _gradeToExecute (gradeToExecute), _signed (false)
{
	if (gradeToSign <= MAX_GRADE || gradeToExecute <= MAX_GRADE)
		throw GradeTooHighException();

	if (gradeToSign >= MIN_GRADE || gradeToExecute >= MIN_GRADE)
		throw GradeTooLowException();
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
Form::getName () const
{
	return _name;
}

int
Form::getGradeToSign () const
{
	return _gradeToSign;
}

int
Form::getGradeToExecute () const
{
	return _gradeToExecute;
}

bool
Form::getSigned () const
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

std::ostream &
operator<< (std::ostream &out, const Form &form)
{
	out << form.getName () << ", grade to sign: "
		<< form.getGradeToSign () << "; grade to execute: "
		<< form.getGradeToExecute ();

	return out;
}
