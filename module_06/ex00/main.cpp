//
// Created by Kevin Di nocera on 11/6/22.
//

#include "scal_conversion.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

char	stock_char(char *str)
{
	char	ret;

	ret = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i])
		{
			ret = str[i];
			break ;
		}
	}
	return (ret);
}

bool	check_if_Number(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (std::isdigit(str[i]) == true)
			i++;
		else if (str[i] == '.' || str[i] == ','
				|| str[i] == 'f' || str[i] == '-')
			i++;

		else
			return (false);
	}
	return (true);
}

bool	check_if_ascii(char *str)
{
	if (std::atoi(str) >= 33 && std::atoi(str) <= 126)
		return (true);
	return (false);
}

int main(int ac, char **av)
{
	double	ret;
	if (ac != 2)
		return (1);
	ret = std::atof(av[1]);
	try
	{
		Scal_conversion	*retn = new Scal_conversion(av[1], ret);
		char 	alpha = stock_char(av[1]);
		int 	intgr = retn->operator int();
		double 	dbl = retn->operator double();
		if (check_if_Number(av[1]))
		{
			if (check_if_ascii(av[1]))
			{
				alpha = retn->operator char();
				std::cout << "◼︎ int:		" << intgr << std::endl;
				std::cout << std::setprecision(5) << std::fixed;
				std::cout << "◼︎ float:	" << ret << "f" << std::endl;
				std::cout << "◼︎ double:	" << dbl << std::endl;
				std::cout << "◼︎ char:		" << alpha << std::endl;
			}
			else
			{
				std::cout << "◼︎ int:		" << intgr << std::endl;
				std::cout << std::setprecision(5) << std::fixed;
				std::cout << "◼︎ float:	" << ret << "f" << std::endl;
				std::cout << "◼︎ double:	" << dbl << std::endl;
				throw Scal_conversion::impossible();
			}
		}
		else
		{
			if (!(strcmp(av[1], "nan")))
				std::cout << BOLD_RED << "int: impossible" << std::endl << "float: nanf" << std::endl
				<< "double: nan" << std::endl << dbl << "char: impossible" << RESET << std::endl;
			else
			{
				if (strlen(av[1]) != 1)
					throw Scal_conversion::moreThanOne();
				std::cout << "◼︎ int:		" << (int(alpha)+0) << std::endl;
				std::cout << std::setprecision(5) << std::fixed;
				std::cout << "◼︎ float:	" << (float(alpha)+0) << "f" << std::endl;
				std::cout << "◼︎ double:	" << (double(alpha)+0) << std::endl;
				std::cout << "◼︎ char:		" << alpha << std::endl;
			}
		}
	}
	catch(std::exception &bc)
	{
		std::cout << bc.what() << std::endl;
	}
	return (0);
}