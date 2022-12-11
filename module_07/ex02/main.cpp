//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Array.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int len;
	len = std::atoi(av[1]);
	len = static_cast<std::size_t>(len);
	Array<void> test(void);
	Array<std::size_t> testParams(std::size_t len);

	return (0);
}