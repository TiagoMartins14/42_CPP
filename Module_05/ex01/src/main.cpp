#include "Bureaucrat.hpp"
#include "Form.hpp"

int
main ()
{
	Bureaucrat *B1 = new Bureaucrat ("B1", 5);
	Form *F1 = new Form ("F1", 4, 2);

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
