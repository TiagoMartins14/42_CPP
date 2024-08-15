#pragma once
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   private:
	AForm *createShrubberyCreationForm(const std::string &target) const;
	AForm *createRobotomyRequestForm(const std::string &target) const;
	AForm *createPresidentialPardonForm(const std::string &target) const;

   public:
	// Constructors and destructor
	Intern();
	Intern(const Intern &other);
	~Intern();

	// Overload
	Intern &operator=(const Intern &copy);

	// Member function
	AForm *makeForm(const std::string &form, const std::string &target) const;
};
