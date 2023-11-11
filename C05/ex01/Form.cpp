#include "Form.hpp"

Form::Form(): _name(""), _isSigned(false), _signGrade(0), _execGrade(0) 
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, int _signGrade, int _execGrade):
	_name(name), _isSigned(false), _signGrade(_signGrade),
	_execGrade(_execGrade)
{
	std::cout << "Form Name Constructor called" << std::endl;
    if (_name != "")
    {
        try
        {
            if (this->_execGrade > 150 || this->_signGrade > 150)
                throw Form::GradeTooLowException();
            else if (this->_execGrade < 1 || this->_signGrade < 1)
                throw Form::GradeTooHighException();			
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr << "Error: Name not provided for the form." << std::endl;
}

Form::Form(Form const &object):
	_name(object._name), _isSigned(object._isSigned),
	_signGrade(object._signGrade), _execGrade(object._execGrade)
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form & Form::operator=(Form const &rhs)
{
	std::cout << "Form Copy Assignment Operator = called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->_name) = rhs.getName();
		const_cast<int&>(this->_signGrade) = rhs.getSignGrade();
		const_cast<int&>(this->_execGrade) = rhs.getExecGrade();
		this->_isSigned= rhs.getSigned();
	}
	return(*this);
}


Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void	Form::beSigned(Bureaucrat const &rhs)
{
    if (_name != "")
        {
            if (rhs.getGrade() <= this->_signGrade)
                this->_isSigned = true;
            else
                throw Form::GradeTooLowException();
        }
        else
            std::cerr << "Error: Form cannot be signed as the form doesn't have a name!" << std::endl;
}

bool	Form::getSigned() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

std::string Form::getName() const
{
	return (this->_name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade Too Low");
}

std::ostream &operator<<(std::ostream &out, Form const &rhs)
{
    if (rhs.getName() != "")
    {
        std::cout << "Form Copy Assignment Operator << called" << std::endl;
        out << "Form name: " << rhs.getName() << std::endl;
        out << "Grade to sign: " << rhs.getSignGrade() << std::endl;
        out << "Grade to execute: " << rhs.getExecGrade() << std::endl;
        out << "Signed: " << rhs.getSigned() << std::endl;

    }
    else 
    {
        out << "Error: Can't print details. Name not provided for the form." << std::endl;
    }
	return (out);
}