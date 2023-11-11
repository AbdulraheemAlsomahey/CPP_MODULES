#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 72, 45), _target(_target)
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &object): AForm(object), _target(object.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = object;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			srand(time(NULL));
			if (rand() % 2)
			{	
				std::cout <<  "[DRILLING NOISES]" << std::endl;
				std::cout << this->_target << " has been robotomized successfully" << std::endl;
			}
			else
				std::cout << " robotomy failed!" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSignedException();
}