#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int
main ()
{
	Bureaucrat *B1 = new Bureaucrat ("B1", 5);
	Form *F1 = new Form ("F1", 4, 2);
	B1->signForm (*F1);
	B1->incrementGrade ();
	B1->signForm (*F1);
}
