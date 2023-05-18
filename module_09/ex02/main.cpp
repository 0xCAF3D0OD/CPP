//
// Created by Kevin Di nocera on 4/2/23.
//
#include "PmergeMe.hpp"

int main(int ac, char **av) {
	PmergeMe test;

	if (ac <= 2 && test.check_args_is_digit(av, ac))
		return (1);
	else if (test.check_args_is_digit(av, ac))
		return (1);
	test.stock_args_string(av, ac);
	test.algo();
	return (0);
}