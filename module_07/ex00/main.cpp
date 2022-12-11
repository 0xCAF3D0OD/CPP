
#include "whatever.hpp"
#include <algorithm>

//int main(int ac, char **av)
//{
//	if (ac != 4)
//	{
//		std::cerr << "less arguments" << std::endl;
//		return (1);
//	}
//	else if (std::isalpha(std::atoi(av[1]) || std::isalpha(std::atoi(av[2]))))
//	{
//		std::cerr << "letter are in the arguments" << std::endl;
//		return (1);
//	}
//	whatever<float>	a(std::atof(av[1]), std::atof(av[2]));
//
//    if (!(strcmp(av[3], "max")))
//	    std::cout << "Biggest => " << a.Max();
//    else if (!(strcmp(av[3], "min")))
//		std::cout << "Smallest => " << a.Min();
//	else if (!(strcmp(av[3], "swap")))
//	{
//		std::cout << "Swap: x = " << av[1] << " and y = " << av[2] << std::endl;
//		a.Swap_x();
//		a.Swap_y();
//		std::cout << "Result of swap: x = " << a.get_x() << " and y = " << a.get_y();
//	}
//	return (0);
//}

int main( void ) {
	int a = 2;
	int b = 3;
	std::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << std::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << std::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << std::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << std::max( c, d ) << std::endl;
	return 0;
}