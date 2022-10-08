//
// Created by dino on 29.09.22.
//
#include "phoneBook.hpp"

// fill all the variable with his correct instance
// take in 1: the name with cin then resize it into a space 10
// take in 2: manage a string longer than 10 size the cut it and put a point at the end
// and etc...
// for the last concatenet the string variable into a array who stock the information with the indexe

void	contact::fillContact(int i)
{
	std::cout << "enter name: ";
	std::cin >> name;
	name.resize(10);
	if (name.size() > 10)
		name.replace(10, name.size(), ".");
	std::cout << "enter first name: ";
	std::cin >> firstName;
	if (firstName.size() > 10)
		firstName.replace(10, firstName.size(), ".");
	firstName.resize(10);
	std::cout << "enter nick name: ";
	std::cin >> nickName;
	if (nickName.size() > 10)
		nickName.replace(10, nickName.size(), ".");
	nickName.resize(10);
	std::cout << "enter phone number: ";
	std::cin >> phoneNumber;
	if (phoneNumber.size() > 10)
		phoneNumber.replace(10, phoneNumber.size(), ".");
	phoneNumber.resize(10);
	std::cout << "enter your biggest secret: ";
	std::cin >> secret;
	if (secret.size() > 10)
		secret.replace(10, secret.size(), ".");
	secret.resize(10);
	contact::tab[i] = firstName + "|" + name + "|" + "\n";
}

// Firstable verify if we are at the zero case of the array
// if it's right access to the public function of class contact
// else the index is now == to the max size of the array we must verify yet if do you want to change someone in the list
// if No ok.
// if Yes you access to the first case of the array you change the information in it with the public fonction of
// class contact who fill all the contact
// then you increment the index for the next time do you want to modify another contact
void	manageContact(contact rep)
{
	int i = 0;
	int idx = 0;
	int size;

	while(1)
	{
		std::cout << "NB: ";
		std::cin >> size;
		if (i <= size) {
			rep.fillContact(i);
			std::cout << "you filled => " << i << " contact\n";
			std::cout << rep.tab[i];
			i++;
		}
		else
		{
			std::cout << "do you want to change someone ? Y or N\n";
			std::cin >> rep.str;
			if (rep.str == "N")
				break ;
			if (rep.str == "Y")
			{
				if (idx != 8)
				{
					std::cout << "insert the word: ";
					rep.fillContact(i);
					idx++;
				}
				else
					idx = 0;
			}
		}
	}
}

// in main function the only purpose is to manage the main input to the choice of the action
// add, search, exit;
int main (void)
{
	contact rep;

	while (1)
	{
		std::cin >> rep.str;
		if (rep.str == "add")
			manageContact(rep);
		if (rep.str == "show")
		{
			for (int i = 0; i <= 8; i++)
				std::cout << "tab[" << i << "]: " << rep.tab[i] << std::endl;
		}
		if (rep.str == "exit")
			break ;
	}
}