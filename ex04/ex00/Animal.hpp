//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_BASE_CLASS_HPP
#define CPP_BASE_CLASS_HPP

#include <iostream>
#include <string>

class Animal
{
private:
	std::string type;
public:
	Animal(void);

	virtual	void 		makeSound(void) const;
	virtual std::string getType(void) const;

	virtual ~Animal(void);
};
#endif //CPP_BASE_CLASS_HPP
