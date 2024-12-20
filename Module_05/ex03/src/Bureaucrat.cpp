#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (std::string name, int grade) : _name (name)
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

Bureaucrat::Bureaucrat (const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat () {}

Bureaucrat &
Bureaucrat::operator= (const Bureaucrat &copy)
{
	if (this != &copy)
		{
			this->_grade = copy._grade;
		}
	return *this;
}

std::string
Bureaucrat::getName ()
{
	return _name;
}

int
Bureaucrat::getGrade ()
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

void
Bureaucrat::signForm (AForm &form)
{
	if (form.getSigned () == true)
		std::cout << _name << " couldn't sign " << form.getName ()
				  << " because form is already signed!" << std::endl;
	else if (_grade <= form.getGradeToSign ())
		{
			form.beSigned (*this);
			std::cout << _name << " signed " << form.getName () << std::endl;
		}
	else
		std::cout << _name << " couldn't sign " << form.getName ()
				  << " because grade is too low!" << std::endl;
	try
		{
			form.beSigned (*this);
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}
}

void 
Bureaucrat::executeForm(AForm const & form)
{
	try
	{
	  	form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
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

const char *
Bureaucrat::AlreadySignedException::what () const throw ()
{
	return "Form is already signed";
}

std::ostream &
operator<< (std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName () << ", bureaucrat grade "
		<< bureaucrat.getGrade () << "." << std::endl;

	return out;
}
