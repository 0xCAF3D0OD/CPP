//
// Created by Kevin Di nocera on 3/25/23.
//

#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <string>
#include <stack>


class	RPN
{
private:
	std::stack<int> stack;
public:
	RPN(void);
	RPN(RPN const &src);

	RPN& 	operator=(RPN const& src);
	int		check_arguments(std::string arg);
	int		calculus(std::string arg);
	int		operator_function(int first, int second, std::string operat);

	~RPN(void);
};
#endif //CPP09_RPN_HPP
