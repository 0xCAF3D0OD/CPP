//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_WHATEVERS_HPP
#define CPP_WHATEVERS_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

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
	whatever	&operator=(whatever const &rhs);

	T const &get_x(void) const {return this->_x;}
	T const &get_y(void) const {return this->_y;}
	~whatever<T>(void){};
private:
	T	const &_x;
	T	const &_y;
	whatever<T>(void);
};
#endif //CPP_WHATEVERS_HPP