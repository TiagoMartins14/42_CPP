#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (const std::string &name, int grade) : _name (name)
{
	if (grade < MAX_GRADE)
		{
			throw GradeTooHighException ();
		}
	else if (grade > MIN_GRADE)
		{
			throw GradeTooLowException ();
		}
	_grade = grade;
}

Bureaucrat::Bureaucrat (const Bureaucrat &other) : _name (other._name)
{ *this = other; }

Bureaucrat::~Bureaucrat () {}

Bureaucrat &
Bureaucrat::operator= (const Bureaucrat &copy)
{
	if (this != &copy)
			this->_grade = copy._grade;
	return *this;
}

const std::string
&Bureaucrat::getName () const
{
	return _name;
}

int
Bureaucrat::getGrade () const
{
	return _grade;
}

void
Bureaucrat::incrementGrade ()
{
	if (_grade - 1 < MAX_GRADE)
		{
			throw GradeTooHighException ();
		}
	_grade--;
}

void
Bureaucrat::decrementGrade ()
{
	if (_grade + 1 > MIN_GRADE)
		{
			throw GradeTooLowException ();
		}
	_grade++;
}

const char *
Bureaucrat::GradeTooHighException::what () const throw ()
{
	return "Grade too high";
}

const char *
Bureaucrat::GradeTooLowException::what () const throw ()
{
	return "Grade too low";
}

std::ostream &
operator<< (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName () << ", bureaucrat grade "
		<< bureaucrat.getGrade () << "." << std::endl;

	return out;
}
