//
// Created by Kevin Di nocera on 10/24/22.
//

#ifndef EX01_HARL_HPP
#define EX01_HARL_HPP

#include <iostream>
#include <string>
// pointer to member function is call with typedef. I made an alias to call it in my function Karen::complain
// all the party from karen to the '*' is the pointer to the member of the classe and then it's the name of the variable with
// the type of the parameter.
class Karen
{
private:
	void			debug(void);
	void			info(void);
	void			warning(void);
	void			error(void);
	typedef void	(Karen::* Krn)(void);
public:
	Karen();

	void	complain(std::string level);

	~Karen();
};

#endif //EX01_HARL_HPP
