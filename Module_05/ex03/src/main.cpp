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

	bureaucrat->signForm(*robotForm);
	robotForm->execute(*bureaucrat);

	delete shrubForm;
	delete robotForm;
	delete presidForm;
	delete fakeNewsForm;
	delete bureaucrat;
}
