
#include "iter.hpp"
#include <algorithm>
#include <cstring>
#include<unistd.h>
//void ft_tolower(char &arr)
//{
//	arr = std::tolower(static_cast<unsigned char>(arr));
//}

//void ft_toupper(char &arr)
//{
//	arr = std::toupper(static_cast<unsigned char>(arr));
//}
//
//int main()
//{
//	char a[] = {'A', 'B', 'C'};
//
//	std::cout << "Original:" <<
//			  "\n\ta[0]: " << a[0] <<
//			  "\n\ta[1]: " << a[1] <<
//			  "\n\ta[2]: " << a[2] <<
//			  std::endl << std::endl;
//
//	::Iter(a, sizeof(a) / sizeof(char), ft_tolower);
//
//	std::cout << "Changed:" <<
//			  "\n\ta[0]: " << a[0] <<
//			  "\n\ta[1]: " << a[1] <<
//			  "\n\ta[2]: " << a[2] <<
//			  std::endl << std::endl;
//
//	::Iter(a, 2, ft_toupper);
//
//	std::cout << "Changed:" <<
//			  "\n\ta[0]: " << a[0] <<
//			  "\n\ta[1]: " << a[1] <<
//			  "\n\ta[2]: " << a[2] <<
//			  std::endl << std::endl;
//}
//void ft_tolower(char &arr)
//{
//	arr = std::tolower(static_cast<unsigned char>(arr));
//}
char	*init_str(char &ret)
{
	char *str = new	char[2];
	str[0] = ret;
	str[1] = '\0';
	return (str);
}

void char_fct(char &ret)
{
	if (ret) {
		int cin = 0;
		do {
			std::cout <<"*---------------------------------------------------------------------*" << std::endl;
			std::cout << "char value = " << BOLD_Y << ret << RESET << std::endl << std::endl
					  << "increment by 1 tap 1 / decrement by 1 tap 2:	";
			std::cin >> cin;
			if (cin == 0)
			{
				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
				exit(1);
			}
			if (cin == 1)
				ret = std::tolower(ret);
			else if (cin == 2)
				ret = std::toupper(ret);
			else
				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
			std::cout << std::endl << BOLD_G << "value is yet = " << ret << RESET << std::endl;
		} while (cin != 1 && cin != 2);

	}
}

void int_fct(char &ret)
{
	if (ret) {
		int cin = 0;
		do {
			int		rtn;
			char	*str;
			str = init_str(ret);
			rtn = std::atoi(str);
			std::cout <<"*---------------------------------------------------------------------*" << std::endl;
			std::cout << "input value = " << BOLD_Y << rtn << RESET << std::endl
					  << "increment by 1 tap 1 / decrement by 1 tap 2:	";
			std::cin >> cin;
			std::cout << std::endl;
			if (cin == 0)
			{
				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
				exit(1);
			}
			if (cin == 1)
				rtn++;
			else if (cin == 2)
				rtn--;
			else
				std::cout << BOLD_RED << "input must be 1 or 2" << RESET << std::endl;
			std::cout << std::endl << BOLD_G << "value is yet = " << rtn << RESET << std::endl;
		} while (cin != 1 && cin != 2);

	}
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "less arguments" << std::endl;
		return (1);
	}
	if (!(strcmp(av[2], "int")))
		Iter(av[1], strlen(av[1]), int_fct);
	if (!(strcmp(av[2], "char")))
		Iter(av[1], strlen(av[1]), char_fct);
	return (0);
}

