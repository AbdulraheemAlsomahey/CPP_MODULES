#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(RobotomyRequestForm const &object);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm();

		std::string	getTarget() const;
		void	execute(Bureaucrat const &executor) const;
};

#endif