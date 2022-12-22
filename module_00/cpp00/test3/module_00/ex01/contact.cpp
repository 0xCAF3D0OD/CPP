//
// Created by Kevin Di nocera on 10/11/22.
//
#include "contact.hpp"

std::string contact::getContact(int i) const
{
	if (i == 1)
		return (_firstName);
	if (i == 2)
		return (_name);
	if (i == 3)
		return (_nickName);
	if (i == 4)
		return (_phoneNumber);
	if (i == 5)
		return (_secret);
	return (NULL);
}

void	contact::fillContact()
{
	std::cout << "for your contact:\n";
	std::cout << "add the first name : ";
	if (!(std::cin >> this->_firstName))
		return ;
	std::cout << "add the name : ";
	if (!(std::cin >> this->_name))
		return ;
	std::cout << "add the nickname : ";
	if (!(std::cin >> this->_nickName))
		return ;
	std::cout << "add the phone number : ";
	if (!(std::cin >> this->_phoneNumber))
		return ;
	std::cout << "add the deepest secret from your contact : ";
	if (!(std::cin >> this->_secret))
		return ;
}

contact::contact() {}
contact::~contact() {}