//
// Created by dino on 29.09.22.
//

#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include <iostream>
#include <string>

class	phoneBook
{
	private:
		std::string contact;
		int 		idx;
	public:

};

class	contact
{
private:
	std::string name;
	std::string firstName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;
public:
	std::string tab[8];
	std::string	str;
	void	fillContact(int i);
	void	searchContact();
	void	printContact() const;

};

#endif //CPP_PHONEBOOK_HPP
