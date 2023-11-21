#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error: Invalid input";
		return 0;
    }
	try
	{
        RPN rpn;
        std::cout << rpn.execute(av[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	
	return 0;
}