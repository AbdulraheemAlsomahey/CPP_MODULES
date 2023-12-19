#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("abdo", 0);
	std::cout << a << std::endl;
	a.gradeIncreament();
	std::cout << a << std::endl;
	a.gradeDecreament();
	std::cout << a << std::endl;
	Bureaucrat b("d7my", 151);
	std::cout << b << std::endl;
	return 0;
}