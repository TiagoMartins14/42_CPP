#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (const std::string &target)
	: AForm ("ShrubberyCreationForm", 145, 137), _target (target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm (
	const ShrubberyCreationForm &other)
	: AForm (other), _target (other._target)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator= (const ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

void
ShrubberyCreationForm::createForm () const
{
	std::ofstream outFile;
	std::string fileName (_target + "_shrubbery");
	struct stat info;

	// Tries to open the file
	outFile.open (fileName.c_str (), std::ofstream::out | std::ofstream::app);
	// Checks if the file is a directory
	if (stat (fileName.c_str (), &info) != 0)
		{
			std::cerr << "Unable to access " << fileName << std::endl;
			return;
		}

	if (outFile.is_open ())
		{
			outFile << "                v .   ._, |_  .,    " << std::endl;
			outFile << "             `-._\\/  .  \\ /    |/_ " << std::endl;
			outFile << "                 \\\\  _\\, y | \\\\//  " << std::endl;
			outFile << "           _\\_.___\\\\, \\\\// -.\\||  " << std::endl;
			outFile << "             `7-,--.`._||  / / ,    " << std::endl;
			outFile << "             /'     `-. `./ / |/_.' " << std::endl;
			outFile << "                       |    |//     " << std::endl;
			outFile << "                       |_    /     " << std::endl;
			outFile << "                       |-   |      " << std::endl;
			outFile << "                       |   =|      " << std::endl;
			outFile << "                       |    |      " << std::endl;
			outFile << "  --------------------/ ,  . \\--------._      "
					<< std::endl;
			outFile.close ();
		}
	return;
}
