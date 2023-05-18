//
// Created by Kevin Di nocera on 3/18/23.
//
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Error: Could not open file" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.init_csv();
	btc.data_base(av[1]);
	return (0);
}
