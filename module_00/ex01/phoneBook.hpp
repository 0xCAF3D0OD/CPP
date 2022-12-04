//
// Created by dino on 29.09.22.
//

#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>
#define BOLD_RED	"\033[1m\033[31m"
#define	RESET   "\033[0m"

class	phoneBook
{
private:
	contact		contactTab[8];
	int 		count;
	std::string firstName_p;
	std::string name_p;
	std::string nickName_p;
public:
	phoneBook(void);
	int 	manage_length(void);
	void	searchContact(void);
	void	displayCmd(void);
	void	displayContact(int i);
	void	displaytab(void);
	void	addContact(void);
	~phoneBook(void);
};


#endif //CPP_PHONEBOOK_HPP
