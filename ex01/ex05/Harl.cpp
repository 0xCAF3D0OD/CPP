//
// Created by Kevin Di nocera on 10/25/22.
//
#include "Harl.hpp"

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

// pointer to function member: I call it in the header.
// I use first an array with the key word, I use an array to use it then in the loop for compare the values
// Then it's the turn for our pointer to the member function, I make an alias in the header with typedef so
// I can use Krn in my function.
// I use a length to stock the 4 addresses from my classe function, they have all a place in the array, so when
// My function compare fund a similitude in the input the idx match with the adresse of the place from the good function.
// if I write INFO in my terminal the loop turn 2 time and the comparing function find a similitude, so it's entering the condition
// and the function complain who hase the same index entering the right function => Karen::info(){}
void	Karen::complain(std::string level)
{
	std::string tabComplain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Krn complain[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++)
	{
		if (tabComplain[i].compare(level) == 0)
		{
			(this->*(complain[i]))();
			return ;
		}
		if (i == 3)
			std::cerr << "wrong input, choose between: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
}
/* so how work the pointer to member function you create a function who has a type a name and a parameter
 * this function take a reference from a another function, you can use this new function to make a similitude
 * action it reducting the redondance of the work. */