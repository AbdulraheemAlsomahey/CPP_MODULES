#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    (void)other;
    return *this;
}

void ScalarConverter::toChar(std::string s)
{
	int i;
	char c;
	std::stringstream ss(s);

  if (s.length() == 1 && isascii(s[0]) && !isdigit(s[0]))
  {
      c = (char)s[0];
      std::cout << "char: " << "\'" << c << "\'" << std::endl;
      return ;
  }
	if (ss >> i)
	{
		if (i >= 0 && i <= 127)
		{
			c = static_cast<char>(i);
			if (c < 32 || c > 126)
				std::cout << "char: Non displayable\n";
			else
				std::cout << "char: '" << c << "'" << std::endl;
		}
		else
			std::cout << "char: impossible\n";
	}
	else
		std::cout << "char: impossible\n";
}

void ScalarConverter::toInt(std::string s)
{
	int i;
	std::stringstream ss(s);

  if (s.length() == 1 && !s.empty() && !isdigit(s[0]))
  {
      i = static_cast<int>(s[0]);
      std::cout << "int: " << i << std::endl;
      return ;
  }
	if (ss >> i)
	{
		i = static_cast<int>(atoi(s.c_str()));
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible\n";
}

void ScalarConverter::toFloat(std::string s)
{
  int i;
	float f;
	std::stringstream ss(s);

    if (s.length() == 1 && !s.empty() && isascii(s[0]) && !isdigit(s[0]))
	{
		i = static_cast<int>(s[0]);
		f = static_cast<float>(i);
		std::cout << "float: " << f << ".0f" << std::endl;
		return ;
	}
    if (ss >> f) 
	{
		if (f - static_cast<int>(f) == 0) 
		{
			std::cout << "float: " << f << ".0f" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << f << "f" << std::endl;
		}
    } 
	else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff") 
	{
        f = std::numeric_limits<float>::infinity();
        std::cout << "float: " << f << "f" << std::endl;
    } 
	else if (s == "-inf" || s == "-inff") 
	{
        f = -std::numeric_limits<float>::infinity();
        std::cout << "float: " << f << "f" << std::endl;
    } 
	else if (s == "nan" || s == "nanf") 
	{
        f = std::numeric_limits<float>::quiet_NaN();
        std::cout << "float: " << f << "f" << std::endl;
    } 
	else 
	{
        std::cout << "float: impossible\n";
    }
}

void ScalarConverter::toDouble(std::string s)
{
  int i;
	double d;
	std::stringstream ss(s);

	if (s.length() == 1 && !s.empty() && isascii(s[0]) && !isdigit(s[0]))
	{
		i = static_cast<int>(s[0]);
		d = static_cast<double>(i);
		std::cout << "double: " << d << ".0" << std::endl;
		return ;
	}
	if (ss >> d)
	{
		d = static_cast<double>(atof(s.c_str()));
		if (d - static_cast<int>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	else if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff")
	{
		d = std::numeric_limits<double>::infinity();
		std::cout << "double: " << d << std::endl;
	}
	else if (s == "-inf" || s == "-inff")
	{
		d = -std::numeric_limits<double>::infinity();
		std::cout << "double: " << d << std::endl;
	}
	else if (s == "nan" || s == "nanf")
	{
		d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "double: impossible\n";
	}
}

void ScalarConverter::handlePseudoLiterals(std::string s)
{
	if (s == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (s == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (s == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (s == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convert(std::string s)
{
	// int i = 0;
	toChar(s);
	toInt(s);
	// std::string pseudo[4] = {"-inff", "+inff", "nanf", "nan"};
	// while (i < 4)
	// {
	// 	if (s == pseudo[i])
	// 	{
	// 		handlePseudoLiterals(s);
	// 		return;
	// 	}
	// 	i++;
	// 	if (i == 4)
	// 	{
	// 		if (s[s.size() - 1] == 'f')
	// 			s.erase(s.size() - 1);
	toFloat(s);
	toDouble(s);
	// 	}
	// }
}