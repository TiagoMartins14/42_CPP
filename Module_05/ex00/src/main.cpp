#include "Bureaucrat.hpp"

int
main ()
{
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

	Bureaucrat *brian = NULL;

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
					brian->incrementGrade ();
				}
			catch (const Bureaucrat::GradeTooHighException &e)
				{
					std::cerr << "Error: " << e.what () << std::endl;
				}
		}
	delete brian;
}
