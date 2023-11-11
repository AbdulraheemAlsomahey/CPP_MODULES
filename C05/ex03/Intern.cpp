#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &object)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = object;
}

Intern & Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string const & name, std::string target)
{
 	std::string	formName[4];
	int			i;

	formName[0] = "shrubbery creation";
	formName[1] = "robotomy request";
	formName[2] = "presidential pardon";
	formName[3] = "NULL";

	for (i = 0; i < 4 ; i++)
		if (!name.compare(formName[i]))
			break;
	switch (i)
	{
		case 0:
			std::cout << "Intern create shrubbery form" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern create robotomy form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern create presidential form" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Not a valid form" << std::endl;
	}
	return (NULL);
}