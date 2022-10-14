//
// Created by dino on 29.09.22.
//

#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>

class	phoneBook
{
private:
	contact		contactTab[8];
	int 		count;
	std::string firstName_p;
	std::string name_p;
	std::string nickName_p;
public:
	phoneBook();
	void	searchContact();
	void	displayCmd();
	void	displayContact(int i);
	void	addContact();
	~phoneBook();
};


#endif //CPP_PHONEBOOK_HPP
