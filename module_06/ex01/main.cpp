//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Data.hpp"
int	check_if_Number(char *str)
{
	int i = 0;
	int idx = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] == '.' || str[i] == ',' || str[i] == 'f')
			idx += 2;
		else if (std::isalpha(str[i]) == true)
		{
			std::cerr << BOLD_RED << "✘ Your input contain letter !!" << RESET << std::endl;
			return (0);
		}
		if (std::isdigit(str[i]) == true)
		{
			if (str[i + 1] == '\0' && idx != 2)
				idx++;
		}
		i++;
	}
	return (idx);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << BOLD_RED << "✘ Not 2 input" << RESET << std::endl;
		return (1);
	}
	int 	var1 = 0;
	double	var2 = 0;
	if (check_if_Number(av[1]) == 1)
		var1 = std::atoi(av[1]);
	if (check_if_Number(av[2]) == 2)
		var2 = std::atof(av[2]);
	if (!var1 || !var2)
	{
		std::cerr << BOLD_RED << "▶︎ First args is a int, the second a double" << RESET << std::endl;
		return (1);
	}
	Data *new_data = new Data(var1, var2);
	uintptr_t raw;

	std::cout << BOLD_Y << "new_data address is:	" << BOLD_G << &new_data << RESET << std::endl;
	std::cout << BOLD_Y << "new_data integer is:	" << BOLD_G << new_data->get_i() << RESET << std::endl;
	std::cout << BOLD_Y << "new_data double is:	" << BOLD_G << new_data->get_flt() << RESET << std::endl << std::endl;
	raw = new_data->serialize(new_data);
	std::cout << BOLD_Y << "raw address is:		" << BOLD_G << &raw << RESET << std::endl << std::endl;
	std::cout << raw << std::endl;
	new_data = new_data->deserialize(raw);
	std::cout << BOLD_Y << "new_data address is:	" << BOLD_G << &new_data << RESET << std::endl;
	std::cout << BOLD_Y << "new_data integer is:	" << BOLD_G << new_data->get_i() << RESET << std::endl;
	std::cout << BOLD_Y << "new_data double is:	" << BOLD_G << new_data->get_flt() << RESET << std::endl << std::endl;
	return (0);
}