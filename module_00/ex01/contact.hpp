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
	std::string _name;
	std::string _firstName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _secret;
	std::string	_str;
public:
	contact();
	void		fillContact();
	std::string	getContact(int i) const;
	void		searchContact(int num);
	~contact();
};

#endif //CPP_CONTACT_HPP
