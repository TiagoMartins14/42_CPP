#pragma once
#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat (const std::string &name, int grade);
	Bureaucrat (const Bureaucrat &other);
	~Bureaucrat ();
	Bureaucrat &operator= (const Bureaucrat &copy);

	const std::string &getName () const;
	int getGrade () const;

	void incrementGrade ();
	void decrementGrade ();

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
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &bureaucrat);
