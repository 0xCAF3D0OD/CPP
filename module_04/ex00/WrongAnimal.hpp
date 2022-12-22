//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_WRONGANIMAL_HPP
#define CPP_WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal
{
private:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &src);

	WrongAnimal	&operator=(WrongAnimal const &rhs);
	virtual	void 		makeSound(void) const;
	virtual std::string getType(void) const;

	~WrongAnimal(void);
};

#endif //CPP_WRONGANIMAL_HPP
