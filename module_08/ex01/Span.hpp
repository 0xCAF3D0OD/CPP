//
// Created by Kevin Di nocera on 12/15/22.
//

#ifndef CPP_SPAN_HPP
#define CPP_SPAN_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <cstdlib>

class Span
{
private:
	unsigned int	_size;
	std::vector<int> _list;

public:
	Span(void);
	Span(unsigned int N);
	Span(Span const &src);

	Span	&operator=(Span const &rhs);

	void				addNumber(unsigned int newInt);
	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);

	void			Crand_number(void);
	unsigned int	get_N(void) const;
	unsigned int	size() const
	{
		return (this->_size);
	}
	class	lessIdx : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	~Span();
};
#endif //CPP_SPAN_HPP
