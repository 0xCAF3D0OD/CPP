//
// Created by Kevin Di nocera on 10/25/22.
//
#include "Harl.hpp"

Karen::Karen()
{
	std::cout << "a Karen a appeared !! FIGHT" << std::endl;
}

Karen::~Karen()
{
	std::cout << "the Karen ran away !! you win" << std::endl;
}

void	Karen::debug()
{
	std::cout << "DEBUG" << std::endl
	<< "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I really do !"
	<< std::endl;
}

void	Karen::info()
{
	std::cout << "INFO" << std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put "
	<< "enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
	<< std::endl;
}
void	Karen::warning()
{
	std::cout << "WARNING" << std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming "
	<< "for years whereas you started working here since last month."
	<< std::endl;
}

void	Karen::error()
{
	std::cout << "ERROR" << std::endl
	<< "This is unacceptable ! I want to speak to the manager now."
	<< std::endl;
}

void	Karen::complain(std::string level)
{
	std::string tabComplain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Krn complain[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++)
	{
		if (!tabComplain[i].compare(level))
		{
			(this->*(complain[i]))();
			return ;
		}
		if (i == 3)
			std::cerr << "wrong input, choose between: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
}
