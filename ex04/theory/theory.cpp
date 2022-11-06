//
// Created by Kevin Di nocera on 11/2/22.
//

#include <iostream>

/*	polymorphism : The same code can automatically adapt to the type of data to which it applies.
 *				  	=> Code that is written in a unifying way for all types of data.
 *				 	With the polymorphism the same code apply to different character can have different action,
 *				 	specific to each.
 *
 *				 	⚠️ reminder =>	inheritance the "child class" inherit from the "parent class":
 *				 					⌲	All the Attribute/Methods (except constructor and destructor).
 *				 					⌲	The type: the object from the "child class" can be affect to a variable
 *				 						from "parent class".
 *				 					Ex:	{		Personnage	p;
 *				 								Guerrier	g;
 *
 *				 								p = g;
 *				 						}
 *
 *				 					⌲	Inherit is transitive:
 *				 						A "magicien" is a "sorcier" who is a "Personnage".
 *
 *				 	"The choice of the methods to be called is made during the execution of the program
 *				 	according to the real nature
 *				 	of the instance concerned" EPFL videos; that depends on the dynamic link resolution;
 *
 *				 	What does it mean:	In c++ it's the type of the variable who determine the methode to execute;
 *				 	⌲	The static link resolution is when the standard call is called (when you add nothing more);
 *				 	⌲	The dynamic link resolution need to be called with "virtual",
 *				 		it must be called in the class "parent"
 *				 					⚬	if the methode is called in the "child" so the methode exists as virtual
 *				 					⚬	in "parent" the methods is allowed because it exists already.
 *
 *				 	⚬ Virtual type:		In C++ Virtual indicate that the Methods is dynamic.
 *
 *				 	⚬ Virtual function/methods:	Member function call in "parent class" who's redefine in "child class".
 *
 *				 	In resume:		When the virtual methods is called from a reference or from a pointer to an
 *				 					"instance" it's the methods from the real type who is executed. => Not the mammal but
 *				 					the dolphin who's called.
 *
 *				 				⚠️	⌲	It's strongly recommended to always define the destructor as virtual.
 *				  					⌲	A constructor can't be virtual.
 *				  					⌲	The aspect virtual is ignored by the methods in the constructor. ⚠️
 *
 * ------------------------------------------------------------------------------------------------------------------------------
 *
 * 	abstract class:	⌲	Is used to impose on the subclasses, that they must redefine the inherited virtual method
 * 					⌲	It's signaled as a =0 at the end of the prototype.
 * 					⌲	In general it's incompletely specified: it has no corps => no definition in the class.
 *
 * 					Abstract class is a class who content at less 1 virtual method pur
 * 					(Pur virtual function => virtual void show() = 0;):
 * 					⌲	Can't be instanced.
 * 					⌲	The subclass stay abstract, as long as it does not provide the definitions from all the pure virtual
 * 						methods inherited. As long, they don't delete the "= 0".
 * 					If the "child class" redefine all the pur virtual methods => the "child class" isn't a abstract class
 * 					any more, but if one of the pur virtual methods isn't redefine in the "child class", the class stay as
 * 					an abstract class.
 * */

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