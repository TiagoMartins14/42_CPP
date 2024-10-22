#pragma once
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

  public:
	// Consttructors and destructor
	AForm (const std::string name, const int gradeToSign,
		   const int gradeToExecute);
	AForm (const AForm &other);
	virtual ~AForm ();
	// Operators
	AForm &operator= (const AForm &copy);

	// Getters
	const std::string &getName () const;
	int getGradeToSign () const;
	int getGradeToExecute () const;
	bool getSigned () const;

	// Form actions
	void beSigned (Bureaucrat &bureaucrat);
	void execute (Bureaucrat const &executor) const;
	virtual void executeAction () const = 0;

	// Excceptions
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

	class FormNotSignedException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};
};

std::ostream &operator<< (std::ostream &out, const AForm &form);
