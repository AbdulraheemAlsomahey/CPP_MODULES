#include "iter.hpp"


int main()
{
	int arrays[] = {1, 2, 3, 4};
	size_t len = 4;

	iter(arrays, len, print<int>);
	std::cout << std::endl;
}