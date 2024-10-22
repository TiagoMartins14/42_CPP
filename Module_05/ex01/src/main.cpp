#include "Bureaucrat.hpp"
#include "Form.hpp"

int
main ()
{
// Creating forms with grades out of bounds
	try
	{
		Form F1 ("F1", 151, 10);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}

	try
	{
		Form F1 ("F1", 10, 151);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}

	try
	{
		Form F1 ("F1", 0, 10);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}

	try
	{
		Form F1 ("F1", 10, 0);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}

// Creating forms with valid grades

	Form *F1 = NULL;
	Bureaucrat *B1 = NULL;

	try
	{
		F1 = new Form ("F1", 4, 2);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}

	try
	{
		B1 = new Bureaucrat ("B1", 5);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what () << std::endl;
	}
	
	std::cout << *B1 << std::endl;
	std::cout << *F1 << std::endl;
	std::cout << "Bureaucrat B1 is attempting to sign form F1..." << std::endl;
	B1->signForm (*F1);
	std::cout << "B1 is getting his grade incremented by one." << std::endl;
	B1->incrementGrade ();
	std::cout << *B1 << std::endl;
	std::cout << "Bureaucrat B1 is attempting to sign form F1..." << std::endl;
	B1->signForm (*F1);
}
