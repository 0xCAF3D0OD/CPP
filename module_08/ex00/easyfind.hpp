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

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#include <algorithm>

//template<typename T>
//typename T::iterator	easyfind( T &container, int goal )
//{
//	typename T::iterator	result = find(container.begin(), container.end(), goal);
//
//	if (result == container.end())
//		return container.end();
//	return result;
//}

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
