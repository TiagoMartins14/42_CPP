#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat *B1 = new Bureaucrat("B1", 50);
  ShrubberyCreationForm *ShrubForm = new ShrubberyCreationForm("ShrubForm");
  RobotomyRequestForm *RobForm = new RobotomyRequestForm("RobForm");
  PresidentialPardonForm *PresForm = new PresidentialPardonForm("PresForm");
  std::cout << *B1 << std::endl;
  std::cout << std::endl;
  std::cout << "ShrubForm sign grade: " << ShrubberyCreationForm::signGrade
            << std::endl;
  std::cout << "ShrubForm execute grade: " << ShrubberyCreationForm::executeGrade
            << std::endl
            << std::endl;
  std::cout << "RobForm sign grade: " << RobotomyRequestForm::signGrade
            << std::endl;
  std::cout << "RobForm execute grade: " << RobotomyRequestForm::executeGrade
            << std::endl
            << std::endl;
  std::cout << "PresForm sign grade: " << PresidentialPardonForm::signGrade
            << std::endl;
  std::cout << "PresForm execute grade: " << PresidentialPardonForm::executeGrade
            << std::endl
            << std::endl;

  // Trying to execute all forms before being signed
  std::cout << "Atempting to execute forms..." << std::endl;
  try {
    ShrubForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    RobForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    PresForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Trying to sign forms
  std::cout << "Atempting to sign forms..." << std::endl;
  try {
    B1->signForm(*ShrubForm);
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error :" << e.what() << std::endl;
  }
  try {
    B1->signForm(*RobForm);
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error :" << e.what() << std::endl;
  }
  try {
    B1->signForm(*PresForm);
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error :" << e.what() << std::endl;
  }

  // Trying to execute all forms after being signed
  std::cout << std::endl <<  "Atempting to execute forms..." << std::endl;
  try {
    ShrubForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    RobForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    PresForm->execute(*B1);
  } catch (const AForm::FormNotSignedException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (const AForm::GradeTooLowException &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  delete B1;
  delete ShrubForm;
  delete RobForm;
  delete PresForm;
}
