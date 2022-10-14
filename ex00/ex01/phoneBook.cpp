//
// Created by Kevin Di nocera on 10/7/22.
//
#include "phoneBook.hpp"

phoneBook::phoneBook()
{
	this->count = 0;
}

phoneBook::~phoneBook() {}

void	phoneBook::displayContact(int num)
{
	int len;
	firstName_p = contactTab[num].getContact(1);
	name_p = contactTab[num].getContact(2);
	nickName_p = contactTab[num].getContact(3);
	if (firstName_p.size() > 10)
		firstName_p.replace(10, 20, ".");
	if (name_p.size() > 10)
		name_p.replace(10, 20, ".");
	if (nickName_p.size() > 10)
		nickName_p.replace(10, 20, ".");
	std::cout << "|" << num << std::setw(10) << "|" ;
	len = firstName_p.size();
	std::cout << firstName_p << std::setw(10 - len) << "|";
	len = name_p.size();
	std::cout << name_p << std::setw(10 - len) << "|";
	len = nickName_p.size();
	std::cout << nickName_p << std::setw(10 - len) << "|\n";
}

void	phoneBook::searchContact()
{
	std::cout << "select the indexe of the contact do you want to see\n";
	std::cout << "insert here: ";
	int num = 0;
	if (!(std::cin >> num))
		return ;
	if (num > 8)
		std::cout << "the indexe you searching for doesn't exist !\n";
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
