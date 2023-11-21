#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
    {}
    return (*this);
}

double RPN::execute(const std::string &value)
{
	std::stack<double> stack;
	std::istringstream iss(value);
	std::string	token;
	
	while(iss >> token)
	{
		if(token.length() != 1 || token.find_first_not_of("0123456789 -+*/") != std::string::npos)
			throw (std::runtime_error("Error\n"));
		if(isdigit(token[0]))
		{
			double num = atof(token.c_str());
			stack.push(num);
		}
		else if(token == "+")
		{
			if(stack.size() < 2)
				throw (std::runtime_error("Error\n"));
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			stack.push(a + b);
		}
		else if(token == "-")
		{
			if(stack.size() < 2)
				throw (std::runtime_error("Error\n"));
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			stack.push(a - b);
		}
		else if(token == "/")
		{
			if(stack.size() < 2)
				throw (std::runtime_error("Error\n"));
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			if (b == 0)
                throw std::runtime_error("Error\n");
			stack.push(a / b);
		}
		else if(token == "*")
		{
			if(stack.size() < 2)
				throw (std::runtime_error("Error\n"));
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			stack.push(a * b);
		}
	}
	if(stack.size() != 1)
		throw (std::runtime_error("Error\n"));
		
	return stack.top();
}