#include "Buraucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade(150) {}

Buracrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	try
		grade < MAX_GRADE;
	catch (const GradeTooHighException& e)
		std::cerr << "Error: " << e.what() << std::endl;

	try
		grade > MIN_GRADE;
	catch (const GradeTooLowException& e)
		std::cerr << "Error: " << e.what() << std::endl;

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
	try
		--grade < MAX_GRADE;
	catch (const GradeTooHighException& e)
		std::cerr << "Error: " << e.what() << std::endl;
}

void Bureaucrat::incrementGrade()
{
	try
		++grade > MIN_GRADE;
	catch (const GradeTooLowException& e)
		std::cerr << "Error: " << e.what() << std::endl;
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
