//
// Created by Kevin Di nocera on 12/7/22.
//

#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"

template<class T>
class	Array
{
private:
	T _n;
	T *_tab;

public:
	Array<void>() : _tab(operator new[](0)){}
	Array<std::size_t>(std::size_t &n) : _n(n), _tab(operator new[](_n))
	{
		std::cout << BOLD_G << "you create an array of "
		<< BOLD_G << _n << RESET << " elements." << std::endl;
		this->_tab(_n) = '\0';
	}
	Array(Array const &src)
	{
		_tab = src._tab;
	}

	Array &operator=(Array const &rhs)
	{
		this->_tab = rhs._tab;
		return (*this);
	}
	void *operator new[](std::size_t size)
	{
		void *copy = ::operator new[](size);
		return (copy);
	}
	Array &operator[](int const &access)
	{
		return (_tab[access]);
	}

	T size(void)
	{
		return (strlen(_tab));
	}

	class	wrongIndex : public std::exception
	{
	public:
		virtual char const *what() const throw()
		{
			std::cout << "wrong access" << std::endl;
		}
	};
	virtual ~Array(void);
};
#endif //CPP_ARRAY_HPP
