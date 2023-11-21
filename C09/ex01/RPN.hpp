#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
    public:

    RPN();
    RPN(const RPN &rhs);
	~RPN();
	RPN &operator=(const RPN &rhs);
    double execute(const std::string &value);
};

#endif