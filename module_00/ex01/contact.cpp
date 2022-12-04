//
// Created by Kevin Di nocera on 10/11/22.
//
#include "contact.hpp"

std::string contact::getContact(int i) const
{
	if (i == 1)
		return (firstName);
	if (i == 2)
		return (name);
	if (i == 3)
		return (nickName);
	return (NULL);
}

void	contact::fillContact()
{
	std::cout << "for your contact:\n";
	std::cout << "add the first name : ";
	if (!(std::cin >> this->firstName))
		return ;
	std::cout << "add the name : ";
	if (!(std::cin >> this->name))
		return ;
	std::cout << "add the nickname : ";
	if (!(std::cin >> this->nickName))
		return ;
	std::cout << "add the phone number : ";
	if (!(std::cin >> this->phoneNumber))
		return ;
	std::cout << "add the deepest secret from your contact : ";
	if (!(std::cin >> this->secret))
		return ;
}

contact::contact() {}
contact::~contact() {}