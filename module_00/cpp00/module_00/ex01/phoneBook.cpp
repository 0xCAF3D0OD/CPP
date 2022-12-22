//
// Created by Kevin Di nocera on 10/7/22.
//
#include "phoneBook.hpp"
#include <stdio.h>

phoneBook::phoneBook()
{
	this->count = 0;
}

phoneBook::~phoneBook() {}

std::string	manage_str(int len_M)
{
	std::string str;

	str.insert(0, "+");
	str.insert(1, len_M - 1, '-');
	str.insert(len_M, 1, '+');

	return (str);
}

void	phoneBook::displaytab(void)
{
	int i;
	int len_M;
	std::string str;
	std::string one;
	std::string two;
	std::string three;

	i = -1;

	len_M = 44;
	str = manage_str(len_M);
	std::cout << str << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "index" << "|" ;
	std::cout << std::setfill(' ') << std::setw(10) << "first name" << "|" ;
	std::cout << std::setfill(' ') << std::setw(10) << "last name" <<"|" ;
	std::cout << std::setfill(' ') << std::setw(10) << "nickname" << "|\n" ;
	while (contactTab[++i].getContact(1).length() != 0)
	{
		one = contactTab[i].getContact(1);
		two = contactTab[i].getContact(2);
		three = contactTab[i].getContact(3);
		if (i == 0)
			std::cout << str << std::endl;
		if (one.size() > 10)
			one.replace(9, 20, ".");
		if (two.size() > 10)
			two.replace(9, 20, ".");
		if (three.size() > 10)
			three.replace(9, 20, ".");
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i << "|" ;
		std::cout << std::setfill(' ') << std::setw(10) << one << "|";
		std::cout << std::setfill(' ') << std::setw(10) << two << "|";
		std::cout << std::setfill(' ') << std::setw(10) << three << "|\n";

		std::cout << str << std::endl;
	}
}

void	phoneBook::displayContact(int num)
{
	int len_M;
	std::string str;

	if (contactTab[num].getContact(1).length() > 0
		|| contactTab[num].getContact(2).length() > 0
		|| contactTab[num].getContact(3).length() > 0)
	{
		_firstName_p = contactTab[num].getContact(1);
		_name_p = contactTab[num].getContact(2);
		_nickName_p = contactTab[num].getContact(3);
		_phoneNumber = contactTab[num].getContact(4);
		_secret = contactTab[num].getContact(5);

		if (_firstName_p.size() > 10)
			_firstName_p.replace(9, 20, ".");
		if (_name_p.size() > 10)
			_name_p.replace(9, 20, ".");
		if (_nickName_p.size() > 10)
			_nickName_p.replace(9, 20, ".");
		if (_phoneNumber.size() > 10)
			_phoneNumber.replace(9, 20, ".");
		if (_secret.size() > 10)
			_secret.replace(9, 20, ".");
		len_M = 66;
		str = manage_str(len_M);

		std::cout << "\n\n" << str << std::endl;
		std::cout << "| " << "your index" << std::setfill(' ') << std::setw(55) << "|" << std::endl;
		std::cout << str << std::endl;

		std::cout << "|" << std::setfill(' ') << std::setw(10) << num << "|";
		std::cout << std::setfill(' ') << std::setw(10) << _firstName_p << "|";
		std::cout << std::setfill(' ') << std::setw(10) << _name_p << "|";
		std::cout << std::setfill(' ') << std::setw(10) << _nickName_p << "|";
		std::cout << std::setfill(' ') << std::setw(10) << _phoneNumber << "|";
		std::cout << std::setfill(' ') << std::setw(10) << _secret << "|\n";
		std::cout << str << std::endl;
	}
	else
		std::cout << std::endl << BOLD_RED << "contact is empty" << std::endl << RESET << std::endl;
}

void	phoneBook::searchContact()
{
	phoneBook::displaytab();
	std::cout << "select the indexe of the contact do you want to see\n";
	std::cout << "insert here: ";
	int num = 0;
	if (!(std::cin >> num))
		return ;
	if (num > 8)
	{
		std::cout << BOLD_RED << "the indexe you searching for doesn't exist !\n" << RESET;
		exit(1);
	}
	phoneBook::displayContact(num);
}

void	phoneBook::addContact()
{
	if (count == 8)
	{
		std::cout << "the contact repertory is full.\n";
		std::cout << "if you want to add a new contact it will delete the oldest one.\n";
		count = 0;
	}
	contactTab[count].fillContact();
	count++;
}

void	phoneBook::displayCmd(void)
{
	std::cout << "if you want to add a contact insert:	ADD\n";
	std::cout << "if you want to search a contact insert:	SEARCH\n";
	std::cout << "if you want to exit the program insert:	EXIT\n";
	std::cout << "insert you choice : ";
}
