#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Name Constructor called" << std::endl;
    if (_name != "")
    {
        try
        {
            if (grade > 150)
                throw Bureaucrat::GradeTooLowException();
            else if (grade < 1)
                throw Bureaucrat::GradeTooHighException();
            else
                this->_grade = grade;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else 
        std::cerr << "Error: Bureacrat must have a name" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &object)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = object;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Copy Assignment Operator = called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::gradeDecreament()
{
    if (_name != "")
    {
        try
        {
            if (this->_grade > 150)
                throw Bureaucrat::GradeTooLowException();
            else if (this->_grade < 1)
                throw Bureaucrat::GradeTooHighException();
            else
                this->_grade++;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "Error: Bureacrat must have a name" << std::endl;
    }
	
}

void	Bureaucrat::gradeIncreament()
{
    if (_name != "")
    {
        try
        {
            if (this->_grade > 150)
                throw Bureaucrat::GradeTooLowException();
            else if (this->_grade < 1)
                throw Bureaucrat::GradeTooHighException();
            else
                this->_grade--;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "Error: Bureacrat must have a name" << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Bureaucrat grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Bureaucrat grade is too Low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Copy Assignment Operator << called" << std::endl;
    if (rhs.getName() != "")
    {
        try
        {
            if (rhs.getGrade() > 150)
                throw std::exception();
            else if (rhs.getGrade() < 1)
                throw std::exception();
            else
                out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << "Grade Not In Range" << std::endl;
        }
    }
    else
    {
        out << "Error: Bureacrat must have a name" << std::endl;
    }
	return (out);
}