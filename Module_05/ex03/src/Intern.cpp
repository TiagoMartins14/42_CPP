#include "Intern.hpp"

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

AForm *Intern::makeForm(std::string &form, std::string &target) const {
	int formIndex = 0;
	const std::string formList[3] = {"shrubbery creation", "robotmy request",
									 "presidential pardon"};

	while (formIndex < 3 && formList[formIndex] != form) formIndex++;

	if (formIndex > 3) {
		std::cout << "The intern does't know how to create such form! - "
				  << form << std::endl;
		return NULL;
	}

	AForm *(Intern::*createFormList[3])(const std::string &target)
		const = {&Intern::createShrubberyCreationForm,
				 &Intern::createRobotomyRequestForm,
				 &Intern::createPresidentialPardonForm};

	std::cout << "The Intern successfully created a " << form << std::endl;

	return (this->*createFormList[formIndex])(target);
}