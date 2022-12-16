 //
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		void		announce() const;
		std::string setName(std::string name);
		int			getNumber(void);
		~Zombie();
};

Zombie *zombieHorde(int N, std::string name);
#endif //CPP_ZOMBIE_HPP
