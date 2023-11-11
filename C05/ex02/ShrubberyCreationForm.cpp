#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShruberryCreationForm", 145, 137), _target(_target)
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &object): AForm(object), _target(object.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = object;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	 ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			try 
			{
				std::string filename = _target + "_shrubbery";
				std::ofstream file(filename.c_str());
				if (file.fail())
					throw ShrubberyCreationForm::MyAppropriateExecption();
				file << "   ^" << std::endl;
				file << "  ^^^" << std::endl;
				file << " ^^^^^" << std::endl;
				file << "^^^^^^^" << std::endl;
				file << "   |" << std::endl;
				file.close();
			}
			catch (std::exception &e) {
				throw;
			}
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSignedException();
	
}

const char *ShrubberyCreationForm::MyAppropriateExecption::what() const throw() {
	return ("Couldn't Create/Open File");
}
