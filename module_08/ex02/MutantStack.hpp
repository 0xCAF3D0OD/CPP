//
// Created by Kevin Di nocera on 12/15/22.
//

#ifndef CPP_MUTANTSTACK_HPP
#define CPP_MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
private:
public:
	MutantStack<T>(void)
	{
		return ;
	}
	MutantStack<T>(const MutantStack<T> &src)
	{
		*this = src;
	}

	MutantStack<T>	&operator=(const MutantStack<T> &rhs)
	{
		(void) rhs;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(void)
	{
		return this->c.begin();
	}
	iterator	end(void)
	{
		return this->c.end();
	}

	static bool	verbose;

	~MutantStack<T>(void)
	{
		return ;
	}
};

#endif //CPP_MUTANTSTACK_HPP
