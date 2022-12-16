//
// Created by Kevin Di nocera on 11/7/22.
//

#include "Span.hpp"

const char *Span::lessIdx::what() const throw()
{
	return ("Less variables in the list\n");
}

Span::Span(void)
:	_size(0)
{
//	std::cout << "scal constructor is called" << std::endl;
}

Span::Span(unsigned int const N)
:	_size(N)
{
//	std::cout << ret << " scal constructor is called" << std::endl;
}

Span::Span(const Span &src)
{
	*this = src;
}
unsigned int	Span::get_N(void) const
{
	return (this->_size);
}

void Span::addNumber(unsigned int newInt)
{
	if (_list.size() <= _size)
		_list.push_back(newInt);
}

unsigned int Span::shortestSpan(void)
{
	int	i = 0;
	int	j = 0;
	int diff = INT_MAX;
	std::vector<int> tmp = _list;
	std::vector<int>::iterator it;

	std::sort(_list.begin(), _list.end());
	for (it = _list.begin(); it != _list.end(); ++it, i++)
	{
		j = 0;
		if ((_list[j + 1] - _list[j]) < diff && _list[j + 1] != '\0')
			diff = *(it + 1) - *it;
		std::cout << *(it + 1) << " - " << *it << " = ";
		std::cout << "	diff = " << diff << std::endl;
	}
	_list = tmp;
	return (diff);
}

unsigned int Span::longestSpan(void)
{
	int	i = 0;
	int MD = _list[1] - _list[0];
	int min = _list[0];
	std::vector<int>::iterator it;

	for (it = _list.begin(); it != _list.end(); ++it, i++)
	{
		if ((_list[i] - min) > MD)
			MD = *it - min;
		if (_list[i] < min)
			min = *it;
	}
	return (MD);
}

void	Span::Crand_number(void)
{
	int				i;
	unsigned int	random;
	for (i = 0; i <= static_cast<int>(_list.size()); i++)
	{
		random = rand();
		addNumber(random);
	}
}

Span &Span::operator=(const Span &rhs)
{
	this->_size = rhs._size;
	return (*this);
}

Span::~Span()
{
//	std::cout << "scal destructor is called" << std::endl;
}
