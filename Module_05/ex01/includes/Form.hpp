#pragma once
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
  private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

  public:
	Form ();
	Form (const std::string name, const int gradeToSign,
		  const int gradeToExecute);
	Form (const Form &other);
	Form &operator= (const Form &copy);
	~Form ();

	const std::string getName ();
	int getGradeToSign ();
	int getGradeToExecute ();
	bool getSigned ();
	void beSigned (Bureaucrat &bureaucrat);

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

std::ostream &operator<< (std::ostream &out, const Form &form);
