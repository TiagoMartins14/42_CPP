#include "Bureaucrat.hpp"

int
main ()
{
// Creating Bureaucrats with out of range grandes
	try
		{
			Bureaucrat adam ("Adam", 0);
		}
	catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}
	catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}

	try
		{
			Bureaucrat adam ("Adam", 151);
		}
	catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}
	catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}
	Bureaucrat *brian = NULL;

// Creating a Bureaucrat with a valid grade
	try
		{
			brian = new Bureaucrat ("Brian", 1);
		}
	catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}
	catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Error: " << e.what () << std::endl;
		}
	if (brian != NULL)
		{
			try
				{
					std::cout << *brian << " It will be incremented by one..." << std::endl; 
					brian->incrementGrade ();
				}
			catch (const Bureaucrat::GradeTooHighException &e)
				{
					std::cerr << "Error: " << e.what () << std::endl;
				}
		}
	for (int i = 1; i <= MIN_GRADE; i++)
	{
		std::cout << *brian << " It will be decremented by one..." << std::endl; 
		try
			{
				brian->decrementGrade ();
			}
		catch (const Bureaucrat::GradeTooLowException &e)
			{
				std::cerr << "Error: " << e.what () << std::endl;
			}
	}
	delete brian;
}
