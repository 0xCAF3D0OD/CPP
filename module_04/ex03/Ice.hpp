//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_ICE_HPP
#define CPP_ICE_HPP

#include "Amateria.hpp"

class ice
{
private:
	std::string clone;
public:
	ice(void);
	ice(ice const &src);

	ice					&operator=(ice const &rhs);
	virtual std::string getClone(void) const;

	virtual ~ice(void);
};
#endif //CPP_ICE_HPP
