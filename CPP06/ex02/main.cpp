
#include "Identify.hpp"

int main()
{
	Base *base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
}