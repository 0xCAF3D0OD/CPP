//
// Created by Kevin Di nocera on 11/6/22.
//

#include "scal_conversion.hpp"

int main(int ac, char **av)
{
	double	ret;
	int 	num;
	if (ac != 2)
		return (1);
	ret = std::atof(av[1]);
	printf("%f\n", ret);
	printf("%d\n", 	std::atoi(av[1]));
	try
	{
		Scal_conversion	*retn = new Scal_conversion(av[1], ret);
		int 	intgr = retn->operator int();
		double 	dbl = retn->operator double();
		num = std::atoi(av[1]);
		if (std::isdigit(num) == 0)
		{
			std::cout << "int: " << intgr << std::endl;
			std::cout << std::setprecision(1) << std::fixed;
			std::cout << "float: " << ret << "f" << std::endl;
			std::cout << "double: " << dbl << std::endl;
			throw Scal_conversion::impossible();
		}
		else
		{
			if (!(strcmp(av[1], "nan")))
				std::cout << "int: impossible" << std::endl << "float: nanf" << std::endl
				<< "double: nan" << std::endl << dbl << "char: impossible" << std::endl;
			else
			{
				if (strlen(av[1]) != 1)
					throw Scal_conversion::moreThanOne();
				std::cout << "int: " << intgr << std::endl;
				std::cout << "float: " << ret << std::endl;
				std::cout << "double: " << dbl << std::endl;
				std::cout << "char: " << retn->get_retn() << std::endl;
			}
		}
	}
	catch(std::exception &bc)
	{
		std::cout << bc.what() << std::endl;
	}
	return (0);
}