//
// Created by Kevin Di nocera on 10/11/22.
//

#include "phoneBook.hpp"

int main(void)
{
	contact		contact;
	phoneBook	book;
	std::string insert;

	while(1)
	{
		book.displayCmd();
		if(!(std::cin >> insert))
			return (0);
		if (insert.c_str() == NULL)
			std::cout << "a command must be enter!\n";
		else if (insert == "ADD")
			book.addContact();
		else if (insert == "SEARCH")
			book.searchContact();
		else if (insert == "EXIT")
			break ;
	}
	return (0);
}
