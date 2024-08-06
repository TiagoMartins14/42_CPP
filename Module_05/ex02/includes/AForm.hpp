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

  protected:
	virtual void executeForm () const = 0;

  public:
	AForm ();
	AForm (const std::string name, const int gradeToSign,
		   const int gradeToExecute);
	AForm (const AForm &other);
	AForm &operator= (const AForm &copy);
	~AForm ();

	const std::string getName ();
	int getGradeToSign ();
	int getGradeToExecute ();
	bool getSigned ();
	void beSigned (Bureaucrat &bureaucrat);
	void execute (Bureaucrat const &executor) const;

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

std::ostream &operator<< (std::ostream &out, const AForm &form);
