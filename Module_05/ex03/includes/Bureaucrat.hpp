#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat (std::string name, int grade);
	Bureaucrat (const Bureaucrat &other);
	~Bureaucrat ();
	Bureaucrat &operator= (const Bureaucrat &copy);

	std::string getName ();
	int getGrade ();

	void incrementGrade ();
	void decrementGrade ();
	void signForm (AForm &form);
	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

	class AlreadySignedException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &bureaucrat);
