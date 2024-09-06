#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &form,
						const std::string &target) const {
	int formIndex = 0;
	const std::string formList[3] = {"shrubbery creation", "robotomy request",
									 "presidential pardon"};

	while (formIndex < 3 && formList[formIndex] != form) formIndex++;
	if (formIndex == 3) {
		std::cout << "The intern does't know how to create a " << form << " form!"
				  << std::endl;
		return NULL;
	}

	AForm *(Intern::*createFormList[3])(const std::string &target)
		const = {&Intern::createShrubberyCreationForm,
				 &Intern::createRobotomyRequestForm,
				 &Intern::createPresidentialPardonForm};

	std::cout << "The Intern successfully created a " << form << " form" << std::endl;

	return (this->*createFormList[formIndex])(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const {
	return new RobotomyRequestForm(target);
}
AForm *Intern::createPresidentialPardonForm(const std::string &target) const {
	return new PresidentialPardonForm(target);
}
