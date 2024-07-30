#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (grade > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		this->_name = copy.name;
		this->_grade = copy.grade;
	}
	return *this;
}

std::string Bureaucrat::getName()
{
	return _name;
}

int	Bureaucrat::getGrade()
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	grade++;
}

const char* Bureaucrat::GradeTooHighExceptio::what() const throw()
	return "Grade too high";

const char* Bureaucrat::GradeTooLowExceptio::what() const throw()
	return "Grade too low";

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std:: endl;

	return out;
}
