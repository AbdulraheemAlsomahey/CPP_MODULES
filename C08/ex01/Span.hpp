#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
    private:
        std::vector<int> _v;
        unsigned int _n;
        class	ContainerEmptyException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	ContainerMaxException : public std::exception
		{
			public:
				const char *what() const throw();
		};
    public:
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &copy);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif