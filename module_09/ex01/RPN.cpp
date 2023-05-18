//
// Created by Kevin Di nocera on 3/26/23.
//
#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	this->stack = src.stack;
	return (*this);
}

int	RPN::check_arguments(std::string arg) {
	std::stringstream ss(arg);
	std::stringstream sa;
	std::string word;
	int			i = 0;

	while (ss >> word) {
		// check if the current location is not a operator
		if ((word.compare("+") != 0) && (word.compare("-") != 0)
			&& (word.compare("*") != 0) && (word.compare("/") != 0))
		{
			// check if all character are digits
			bool all_digits = true;
			for(size_t j = 0; j < word.size(); ++j)
			{
				if (!std::isdigit(word[j])) {
					all_digits = false;
					break ;
				}
			}
			// return error
			if (!all_digits) {
				std::cerr << "Error: Not all arguments are digits." << std::endl;
				return (1);
			}
			// check if the digit is bigger than 9 or lower than 0
			sa << word;
			if ((sa >> i && (i > 9 || i < 0))) {
				std::cerr << "Number is superior as 10 or less than 0" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int	RPN::operator_function(int first, int second, std::string operat) {
	int res = 0;

	if (!operat.compare("+"))
		res = first + second;
	else if (!operat.compare("-"))
		res = first - second;
	else if (!operat.compare("*"))
		res = first * second;
	else if (!operat.compare("/"))
		res = first / second;
//	std::cout << "evolution of the result: " << res << std::endl;
	return (res);
}

int	RPN::calculus(std::string arg) {
	std::stringstream ss(arg);
	std::stringstream sa;
	std::string word;
	int	i = 0;
	int res = 0;
	int first = 0;
	int second = 0;

	std::cout << "argument: " << arg << std::endl;

	while (ss >> word) {
		if ((word.compare("+")) && (word.compare("-")) && (word.compare("*")) && (word.compare("/")))
		{
			std::cout << word.c_str() << std::endl;
			i = std::atoi(word.c_str());
			stack.push(i);
			continue ;
		}
		if (stack.size() < 2)
		{
			std::cerr << "Error: size of argument less than 2." << std::endl;
			return (1);
		}
		std::cout << stack.size() << " " << stack.top() << std::endl;
		second = stack.top();
		stack.pop();
		first = stack.top();
		stack.pop();
		res = operator_function(first, second, word);
		stack.push(res);
	}
	if ((word.compare("+")) && (word.compare("-")) && (word.compare("*")) && (word.compare("/")))
	{
		std::cerr << "Error: The input is not conventional, last element must be an operator" << std::endl;
		return (1);
	}
	std::cout << "the result: "<< stack.top() << std::endl;
	return (0);
}

RPN::~RPN() {}