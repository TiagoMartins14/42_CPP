#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Intern someRandomIntern;
	AForm* shrubForm;
	AForm* robotForm;
	AForm* presidForm;
	AForm* fakeNewsForm;
	Bureaucrat* bureaucrat;

	shrubForm = someRandomIntern.makeForm("shrubbery creation", "Bender");
	robotForm = someRandomIntern.makeForm("robotomy request", "Cleo");
	presidForm = someRandomIntern.makeForm("presidential pardon", "Donald");
	fakeNewsForm = someRandomIntern.makeForm("fake news", "Easton");

	bureaucrat = new Bureaucrat("Andrew", 1);

// Trying to execute before signing
	try
	{
		robotForm->execute(*bureaucrat);
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

// Trying to sign the form
	try
	{
		bureaucrat->signForm(*robotForm);
  	}
	catch (const AForm::GradeTooLowException &e)
	{
    	std::cerr << "Error :" << e.what() << std::endl;
  	}

// Trying to execute after signing the form
	try
	{
	  	robotForm->execute(*bureaucrat);
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	delete shrubForm;
	delete robotForm;
	delete presidForm;
	delete fakeNewsForm;
	delete bureaucrat;
}
