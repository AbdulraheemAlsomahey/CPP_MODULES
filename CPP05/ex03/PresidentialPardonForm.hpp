#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(PresidentialPardonForm const &object);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm();

		std::string	getTarget() const;
		void	execute(Bureaucrat const &executor) const;
};

#endif