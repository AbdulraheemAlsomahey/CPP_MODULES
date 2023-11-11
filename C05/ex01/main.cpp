#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat _B("abdo", 42);
	Form _F("AnyForm", 2, 75);
	
	_B.signForm(_F);
	std::cout << _B;
}