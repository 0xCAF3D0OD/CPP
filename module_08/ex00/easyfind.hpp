//
// Created by Kevin Di nocera on 12/14/22.
//

#ifndef CPP_EASYFIND_HPP
#define CPP_EASYFIND_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

template <typename T>
int	easyfind(T arg1, int arg2)
{
	typename T::iterator ret;

	ret = std::find(std::begin(arg1), std::end(arg1), arg2);
	if ((ret == std::end(arg1)))
		return (0);
	else
		return (arg2);
}

class	wrongArgs : public std::exception
{
public:
	virtual const char	*what() const throw();
};

class	occurence : public std::exception
{
public:
	virtual const char	*what() const throw();
};

class	noOccurence : public std::exception
{
public:
	virtual const char	*what() const throw();
};
#endif //CPP_EASYFIND_HPP
