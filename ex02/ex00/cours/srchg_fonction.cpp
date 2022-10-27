//
// Created by Kevin Di nocera on 10/26/22.
//
#include <iostream>
/*	*	Polymorphisme Ad-hoc (surcharge de fonction): let you initializing function with the same name but with different parameter.
 *		it's work with all type of function.
 *	*	Polymorphisme Ad-hoc (surcharge d'opérateur):
*/
class sample
{
public:
	sample();
	~sample();

	void	keke(char const c) const;
	void	keke(int const n) const;
	void	keke(float const z) const;
	void	keke(sample const &i) const;
};

sample::sample()
{
	std::cout << "hello world" << std::endl;
}
sample::~sample()
{
	std::cout << "byby world" << std::endl;
}

int main(void)
{
	sample	keke;


	return (0);
}