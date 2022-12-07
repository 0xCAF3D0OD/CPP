//
// Created by Kevin Di nocera on 11/2/22.
//

#include <iostream>
#include <typeinfo>
#include <exception>

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

class	Foo {
public:
	Foo(float const v) : _v(v){}

	float	getv(void) {return this->_v;}

	operator	float() {return this->_v;}
	operator	int() {return static_cast<int>(this->_v);}
private:
	float _v;
};

int main(void)
{
	Foo		a(420.024f);
	float	b = a;
	int		c = a;

	std::cout << a.getv() << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}

//const_cast
//class	Parents{};
//class	child1 : public Parents{};
//class	child2 : public Parents{};
//
//int main(void)
//{
//	int a = 42;
//
//	int const*	b = &a;						//implicit promotion float -> void*
//	int*	c = b;							//implicit demotion void* -> int*
//	int*	d = const_cast<int *>(b);		//explicit demotion void& -> int&
//
//	return (0);
//}

//reinterpret_cast
//class	Parents{};
//class	child1 : public Parents{};
//class	child2 : public Parents{};
//
//int main(void)
//{
//	float a = 420.042f;
//
//	void*	b = &a;								//implicit promotion float -> void*
//	int*	c = reinterpret_cast<int *>(b);;	//explicit demotion void* -> int*
//	int&	d = reinterpret_cast<int &>(b);		//explicit demotion void& -> int&
//
//	return (0);
//}

//dynamic cast
//class	Parents{ public: virtual ~Parents(void){} };
//class	child1 : public Parents{};
//class	child2 : public Parents{};
//
//class Unrelated{};
//
//int main(void)
//{
//	child1 a;
//	Parents*	b = &a;
//
//	child1*		c = dynamic_cast<child1 *>(b);
//	if (c == NULL)
//		std::cout << "conversion is not OK" << std::endl;
//	else
//		std::cout << "conversion is OK" << std::endl;
//	try
//	{
//		child2&	d = dynamic_cast<child2 &>(*b);
//		std::cout << "conversion is OK" << std::endl;
//	}
//	catch (std::bad_cast &bc)
//	{
//		std::cout << "conversion is not OK" << bc.what() << std::endl;
//		return (0);
//	}
//	return (0);
//}

//static cast
//class	Parents{};
//class	child1 : public Parents{};
//class	child2 : public Parents{};
//
//class Unrelated{};
//
//int main(void)
//{
//	child1 a;
//
//	Parents*	b = &a;
//	child1*		c = b;
//	child2*	 	d = static_cast<child2 *>(b);
//
//	Unrelated* 	e = static_cast<Unrelated *>(&a);
//
//	return (0);
//}

//upcast downcast
//class	Parents{};
//class	child1 : public Parents{};
//class	child2 : public Parents{};
//
//int main(void)
//{
//	child1 	a;
//
//	Parents*	b = &a;
//	Parents*	c = (Parents*) &a;
//	Parents*	d = &a;
//
//	child1*		e = d;
//	child2*		f = (child2 *) d;
//
//	printf("%p, %d\n", &a, a);
//
//	printf("%p\n",b);
//	printf("%p\n",c);
//
//	printf("%p\n",d);
////	printf("%p, %d\n", e, e);
////	printf("%p, %d\n", f, f);
//
//	return (0);
//}
//reinterpretation
//int main(void)
//{
//	float 	a = 420.042f;
//
//	void*	b = &a;
//	void*	c = (void*) &a;
//	void*	d = &a;
//
//	int*	e = d;
//	int*	f = (int *) d;
//
//	printf("%p, %f\n", &a, a);
//
//	printf("%p\n",b);
//	printf("%p\n",c);
//
//	printf("%p\n",d);
//	printf("%p, %d\n", e, *e);
//	printf("%p, %d\n", f, *f);
//
//	return (0);
//}

//conversion
//int main(void)
//{
//	int		a = 42;
//
//	double	b = a;
//	double	c = (double) a;
//	double	d = a;
//
//	int		e = d;
//	int		f = (int) d;
//
//	return (0);
//}