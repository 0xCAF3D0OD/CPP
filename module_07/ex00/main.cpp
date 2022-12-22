
#include "whatever.hpp"

int	manage_error(std::string value_1, std::string value_2)
{
	int i = 0;
	try
	{
		if (value_1.find_first_not_of("0123456789.f,") == std::string::npos &&
			value_2.find_first_not_of("0123456789.f,") == std::string::npos)
			i = 1;
		if (!std::strcmp(value_1.c_str(), ".") || !std::strcmp(value_2.c_str(), ".") || !std::strcmp(value_1.c_str(), ",") ||
			!std::strcmp(value_2.c_str(), ",") || !std::strcmp(value_1.c_str(), "f") || !std::strcmp(value_2.c_str(), "f"))
			i = 0;
		if (!i)
			throw inputNotDigitException();
	}
	catch (inputNotDigitException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return (0);
}

int main(void)
{
	std::string	value_1;
	std::string	value_2;
	std::string cmd;

	std::cout << BOLD_Y << "\n INFO: This exercise take values and with your choice compare max with min or swap values\n\n" << RESET;
	std::cout << "	☐ Put the first value : ";
	std::cin >> value_1;
	std::cout << "	☐ Put the second value : ";
	std::cin >> value_2;
	std::cout << std::endl;

	if (manage_error(value_1, value_2))
		return (1);

	whatever<float>	a(std::atof(value_1.c_str()), std::atof(value_2.c_str()));

	std::cout << "	☐ if you want to see the max value put " << BOLD_RED << "max" << RESET
	<< " if min value put "<< BOLD_RED << "min" << RESET
	<< " or swap the value put " << BOLD_RED << "swap" << RESET << ": ";
	std::cin >> cmd;

	if (!(strcmp(cmd.c_str(), "max")))
	    std::cout << "	☐ Biggest → " << BOLD_G << a.Max() << RESET << std::endl;
    else if (!(strcmp(cmd.c_str(), "min")))
		std::cout << "	☐ Smallest → " << BOLD_G << a.Min() << RESET << std::endl;
	else if (!(strcmp(cmd.c_str(), "swap")))
	{
		std::cout << std::endl << "	☐ Swap: x = " << BOLD_G << value_1 << RESET << " and y = " << BOLD_G << value_2 << RESET << std::endl;
		a.Swap_x();
		a.Swap_y();
		std::cout << "	→ Result of swap: x = " << BOLD_G << a.get_x() << RESET << " and y = " << BOLD_G << a.get_y() << RESET << std::endl;
	}

	return (0);
}

//int main( void ) {
//	int a = 2;
//	int b = 3;
//	std::swap( a, b );
//	std::cout << "a = " << a << ", b = " << b << std::endl;
//	std::cout << "min( a, b ) = " << std::min( a, b ) << std::endl;
//	std::cout << "max( a, b ) = " << std::max( a, b ) << std::endl;
//	std::string c = "chaine1";
//	std::string d = "chaine2";
//	std::swap(c, d);
//	std::cout << "c = " << c << ", d = " << d << std::endl;
//	std::cout << "min( c, d ) = " << std::min( c, d ) << std::endl;
//	std::cout << "max( c, d ) = " << std::max( c, d ) << std::endl;
//	return 0;
//}