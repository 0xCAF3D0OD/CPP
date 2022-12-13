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

template<typename T>

class whatever
{
public:
	whatever<T>(T const &x, T const &y) : _x(x), _y(y){}
	whatever(whatever const &src);

	T Max(void)
	{
		return (_x >= _y ? _x : _y);
	}
	T Min(void)
	{
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
#endif //CPP_WHATEVERS_HPP