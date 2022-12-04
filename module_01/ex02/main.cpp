//
// Created by Kevin Di nocera on 10/13/22.
//
#include <iostream>

void printAdresse(std::string const &str)
{
	std::cout << &str << std::endl;
}

void printString(std::string const *str)
{
	std::cout << *str << std::endl;
}

int main (void)
{
	std::string brain =  "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string	&stringREF = brain;

	printAdresse(brain);
	printAdresse(*stringPTR);
	printAdresse(stringREF);
	printString(&brain);
	printString(stringPTR);
	printString(&stringREF);

	return (0);
}