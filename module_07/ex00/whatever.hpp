//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_WHATEVERS_HPP
#define CPP_WHATEVERS_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"

template<typename T>

class whatever
{
public:
	whatever<T>(T const &x, T const &y) : _x(x), _y(y){}
	whatever(whatever const &src);

	T Max(void)
	{
		if (_x == _y)
			return (_y);
		return (_x >= _y ? _x : _y);
	}
	T Min(void)
	{
		if (_x == _y)
			return (_y);
		return (_x <= _y ? _x : _y);
	}
	T Swap_x(void)
	{
		_temp = _x;
		return (_x = _y);
	}
	T Swap_y(void)
	{
		return (_y = _temp);
	}

	whatever	&operator=(whatever const &rhs);
	T const &get_x(void) const {return this->_x;}
	T const &get_y(void) const {return this->_y;}

	~whatever<T>(void){};
private:
	T	_x;
	T	_y;
	T	_temp;
	whatever<T>(void);
};

class	inputNotDigitException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (BOLD_RED "\n✘ The input is not a int or is equal to 0\n" RESET);
	}
};

class	inputNotCharException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (BOLD_RED "\n✘ The input is not a char or is equal to 0\n" RESET);
	}
};

class	inputNotfloatException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (BOLD_RED "\n✘ The input is not a float or is equal to 0\n" RESET);
	}
};

class	inputNotDoubleException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (BOLD_RED "\n✘ The input is not a double or is equal to 0\n" RESET);
	}
};

class	inputNotCmdException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (BOLD_RED "\n✘ The input is the right cmd\n" RESET);
	}
};

#endif //CPP_WHATEVERS_HPP