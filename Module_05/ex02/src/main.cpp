#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int
main ()
{
	Bureaucrat *B1 = new Bureaucrat ("B1", 5);
	ShrubberyCreationForm *ShrubForm = new ShrubberyCreationForm ("ShrubForm");
	RobotomyRequestForm *RobForm = new RobotomyRequestForm ("RobForm");
	PresidentialPardonForm *PresForm = new PresidentialPardonForm ("PresForm");
	B1->signForm (*ShrubForm);
	B1->signForm (*RobForm);
	B1->signForm (*PresForm);

	ShrubForm->execute (*B1);
	RobForm->execute (*B1);
	PresForm->execute (*B1);

	delete B1;
	delete ShrubForm;
	delete RobForm;
	delete PresForm;
}
