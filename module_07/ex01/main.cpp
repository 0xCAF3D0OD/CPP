
#include "iter.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

//char	*init_str(char &ret)
//{
//	char *str = new	char[2];
//	str[0] = ret;
//	str[1] = '\0';
//	return (str);
//}
//
//void char_fct(char &ret)
//{
//	if (ret) {
//		int cin = 0;
//		do {
//			std::cout <<"*---------------------------------------------------------------------*" << std::endl;
//			std::cout << "char value = " << BOLD_Y << ret << RESET << std::endl << std::endl
//					  << "to lower case tap 1 / to upper case tap 2: ";
//			std::cin >> cin;
//			if (cin == 0)
//			{
//				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
//				exit(1);
//			}
//			if (cin == 1)
//				ret = std::tolower(ret);
//			else if (cin == 2)
//				ret = std::toupper(ret);
//			else
//				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
//			std::cout << std::endl << BOLD_G << "value is yet = " << ret << RESET << std::endl;
//		} while (cin != 1 && cin != 2);
//
//	}
//}
//
//void int_fct(char &ret)
//{
//	if (ret) {
//		int cin = 0;
//		do {
//			int		rtn;
//			char	*str;
//			str = init_str(ret);
//			rtn = std::atoi(str);
//			std::cout <<"*---------------------------------------------------------------------*" << std::endl;
//			std::cout << "input value = " << BOLD_Y << rtn << RESET << std::endl
//					  << "increment by 1 tap 1 / decrement by 1 tap 2: ";
//			std::cin >> cin;
//			std::cout << std::endl;
//			if (cin == 0)
//			{
//				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
//				exit(1);
//			}
//			if (cin == 1)
//				rtn++;
//			else if (cin == 2)
//				rtn--;
//			else
//				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
//			std::cout << std::endl << BOLD_G << "value is yet = " << rtn << RESET << std::endl;
//		} while (cin != 1 && cin != 2);
//
//	}
//}
//
//int	manage_error(std::string value, std::string type)
//{
//	int i = 0;
//	try
//	{
//		if (value.find_first_not_of("0123456789") == std::string::npos)
//			i = 1;
//		if (value.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos ||
//			value.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos )
//			i = 2;
//		if (std::strcmp(type.c_str(), "char") || std::strcmp(type.c_str(), "int"))
//			throw wrongInputException();
//		if (!std::strcmp(type.c_str(), "char") && i != 2)
//			throw inputNotCharException();
//		else if (!std::strcmp(type.c_str(), "int") && i != 1)
//			throw inputNotDigitException();
//	}
//	catch (wrongInputException &exe) {
//		std::cerr << exe.what() << std::endl;
//		return (1);
//	}
//	catch (inputNotCharException &exe) {
//		std::cerr << exe.what() << std::endl;
//		return (1);
//	}
//	catch (inputNotDigitException &exe) {
//		std::cerr << exe.what() << std::endl;
//		return (1);
//	}
//	return (0);
//}
//
//int main(void)
//{
//	std::string	type;
//	std::string	value;
//
//	std::cout << BOLD_Y << "\n INFO: This exercise take a type and his value and with your choice increment other decrement his value\n\n" << RESET;
//	std::cout << "	☐ Put the type input : ";
//	std::cin >> type;
//	std::cout << "	☐ Put the value input : ";
//	std::cin >> value;
//	if (manage_error(value, type))
//		return (1);
//	char	value_C[value.length() + 1];
//	std::strcpy(value_C, value.c_str());
//	if (!std::strcmp(type.c_str(), "int"))
//		Iter(value_C, std::strlen(value_C), int_fct);
//	if (!std::strcmp(type.c_str(), "char"))
//		Iter(value_C, std::strlen(value_C), char_fct);
//	return (0);
//}

#include <iostream>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" <<
			  "\n\ta[0]: " << a[0] <<
			  "\n\ta[1]: " << a[1] <<
			  "\n\ta[2]: " << a[2] <<
			  std::endl << std::endl;

	Iter(a, sizeof(a) / sizeof(char), ft_tolower);

	std::cout << "Changed:" <<
			  "\n\ta[0]: " << a[0] <<
			  "\n\ta[1]: " << a[1] <<
			  "\n\ta[2]: " << a[2] <<
			  std::endl << std::endl;

	Iter(a, 2, ft_toupper);

	std::cout << "Changed:" <<
			  "\n\ta[0]: " << a[0] <<
			  "\n\ta[1]: " << a[1] <<
			  "\n\ta[2]: " << a[2] <<
			  std::endl << std::endl;
}