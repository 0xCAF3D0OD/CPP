//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_WRONGCAT_HPP
#define CPP_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
private:
	std::string	_type;
public:
	WrongCat(void);
	WrongCat(WrongCat const &src);

	WrongCat	&operator=(WrongCat const &rhs);
	std::string	getType(void) const;
	void		makeSound(void) const;

	~WrongCat(void);
};
#endif //CPP_WRONGCAT_HPP
