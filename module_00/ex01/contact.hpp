//
// Created by Kevin Di nocera on 10/11/22.
//

#ifndef CPP_CONTACT_HPP
#define CPP_CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class	contact
{
private:
	std::string name;
	std::string firstName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;
	std::string	str;
public:
	contact();
	void		fillContact();
	std::string	getContact(int i) const;
	void		searchContact(int num);
	~contact();
};

#endif //CPP_CONTACT_HPP
