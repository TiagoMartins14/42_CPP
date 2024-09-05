#include "AForm.hpp"

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
AForm::getName () const
{
	return _name;
}

int
AForm::getGradeToSign () const
{
	return _gradeToSign;
}

int
AForm::getGradeToExecute () const
{
	return _gradeToExecute;
}

bool
AForm::getSigned () const
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

void
AForm::execute (Bureaucrat const &executor) const
{
	if (((Bureaucrat &)executor).getGrade () > this->_gradeToExecute)
		throw AForm::GradeTooLowException ();
	else if (!this->_signed)
		throw AForm::FormNotSignedException ();
	else
		this->executeAction ();
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

const char *
AForm::FormNotSignedException::what () const throw ()
{
	return "Form is already signed";
}

std::ostream &
operator<< (std::ostream &out, const AForm &aform)
{
	out << aform.getName () << ", grade to sign: "
		<< aform.getGradeToSign () << "; grade to execute: "
		<< aform.getGradeToExecute ();

	return out;
}
