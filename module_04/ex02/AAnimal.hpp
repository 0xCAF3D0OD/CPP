//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_BASE_CLASS_HPP
#define CPP_BASE_CLASS_HPP

#include <iostream>
#include <string>

class AAnimal
{
private:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(AAnimal const &src);

	AAnimal	&operator=(AAnimal const &rhs);
	virtual	void 		makeSound(void) const = 0;
	virtual std::string getType(void) const;

	virtual ~AAnimal(void);
};
#endif //CPP_BASE_CLASS_HPP
