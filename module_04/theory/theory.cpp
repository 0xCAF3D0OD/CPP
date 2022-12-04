//
// Created by Kevin Di nocera on 11/2/22.
//

#include <iostream>

class Mammifere
{
public:
			Mammifere() { std::cout << "Un nouveau mammifère est né !" << std::endl;}
	virtual ~Mammifere() { std::cout << "Un mammifère est mort !" << std::endl;}
			void	manger() const { std::cout << "miam... croumf !" << std::endl; }
	virtual void	avancer() const { std::cout << "un grand pas pour l'humanité. !" << std::endl; }
};

class Dauphin : public Mammifere
{
public:
	Dauphin() { std::cout << "coui, couic !" << std::endl; }
	~Dauphin() { std::cout << "flipper, c'est fini... !" << std::endl; }
	void	manger() const { std::cout << "Sglup, un poisson !" << std::endl; }
	void	avancer() const { std::cout << "Je nage." << std::endl; }
};

int main(void) {

	Mammifere *lui = new Dauphin();
	lui->avancer();
	lui->manger();
	delete lui;
	return (0);
}