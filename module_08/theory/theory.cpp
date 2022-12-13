//
// Created by Kevin Di nocera on 11/2/22.
#include <iostream>
#include <typeinfo>
#include <exception>
#include <iomanip>

template<typename T, typename U>

class	Pair {
public:
	Pair<T, U>(T const &x, U const &y) : _x(x), _y(y) {
		std::cout << "generic template" << std::endl;
		return ;
	}
	~Pair<T, U>(void) {}

	T const &get_x(void) const {return this->_x;}
	U const &get_y(void) const {return this->_y;}

private:
	T const &_x;
	U const &_y;

	Pair<T, U>(void);
};

/******************************************************************************************************************************/

template<typename U> // partial because U still exist but T don't exist anymore.

class	Pair<int, U> { // we specify which type we use in the class. we specialize the int and retrieve the U
public:
	Pair<int, U>(int const &x, U const &y) : _x(x), _y(y) {
		std::cout << "int partial specialisation" << std::endl;
		return ;
	}
	~Pair<int, U>(void) {}

	int get_x(void) const {return this->_x;}
	U const &get_y(void) const {return this->_y;}

private:
	int const _x;
	U const _y;

	Pair<int, U>(void);
};

/******************************************************************************************************************************/

template<> // complet because U and T don't exist anymore.
class	Pair<bool, bool> { // we specify which type we use in the class. we specialize the int and retrieve the U
public:
	Pair<bool, bool>(bool x, bool y){
		std::cout << "bool bool specialisation" << std::endl;
		this->_n = 0; 							// initialisation variable n;
		this->_n |= static_cast<int>(x) << 0;	// sign or/equal, bitshift first bits
		this->_n |= static_cast<int>(y) << 1;	// bitshift seconde bits
		return ;
	}
	~Pair<bool, bool>(void) {}

	bool get_x(void) const {return (this->_n & 0x01);} // and binary to retrieve the first bites
	bool get_y(void) const {return (this->_n & 0x02);} // and binary to retrieve the seconde bites

private:
	int _n;

	Pair<bool, bool>(void);
};

/******************************************************************************************************************************/

template<typename T, typename U>
std::ostream &operator<<(std::ostream &o, Pair<T, U> const &v)
{
	o << "Pair( " << v.get_x() << ", " << v.get_y() << " )";
	return (o);
}
std::ostream &operator<<(std::ostream &o, Pair<bool, bool> const &v)
{
	o << "Pair( " << v.get_x() << ", " << v.get_y() << " )";
	return (o);
}

int main(void)
{
	Pair<int, int>	p1(4,2);
	Pair<std::string , int>	p2(std::string (" pi "),2);
	Pair<float, bool>	p3(4.2f, true);
	Pair<bool, bool>	p4(true,false);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
	return (0);
}

//template<typename T = float> //default type.
//
//class	Vertex {
//public:
//	Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}
//	~Vertex(void) {}
//
//	T const get_x(void) const {return this->_x;}
//	T const get_y(void) const {return this->_y;}
//	T const get_z(void) const {return this->_z;}
//
//private:
//	T const _x;
//	T const _y;
//	T const _z;
//
//	Vertex(void); // put the constructor in private section required the user to put value. (three in this example).
//};
//
//template<typename T>
//
//std::ostream &operator<<(std::ostream &o, Vertex<T> const &v)
//{
//	std::cout.precision(1);
//	o << std::setiosflags(std::ios::fixed);
//	o << "vertex (";
//	o << v.get_x();
//	o << v.get_y();
//	o << v.get_z();
//	o << ")";
//	return (o);
//}
//
//int main(void)
//{
//	Vertex<int>	v1(42, 54, 3);
//	Vertex<>	v2(42, 54, 3);
//	std::cout << v1 << std::endl;
//	std::cout << v2 << std::endl;
//
//	return (0);
//}
//template<typename T>
//
//class	List {
//public:
//	List<T>(T const &content) {}
//	List<T>(List<T> const &List) {}
//	List<T>(void) {}
//
//privat\

// 	T *_constent;
//	List<T> *_next;
//};
//
//int	main(void)
//{
//	List<int>		a(42);
//	List<float>		b(3.14f);
//	List<List<int>>	c(a);
//
//	return (0);
//}
//T const &max(T const &x, T const &y)
//{
//	return (x>=y ? x : y);
//}
//
////int max(int x, int y)
////{
////	return (x>=y ? x : y);
////}
//
//int	foo(int x)
//{
//	std::cout << "Long computing time" << std::endl;
//	return (x);
//}
//
//int main(void)
//{
//	int	a = 21;
//	int b = 42;
//
//	std::cout << "Max of " << a << " and " << b << " is ";
//	std::cout << max<int>(a, b) << std::endl;		// explicit instantation.
//	std::cout << "Max of " << a << " and " << b << " is ";
//	std::cout << max(a, b) << std::endl;			// implicit instantation.
//
//
//	float	c = -1.7f;
//	float	d = 4.2f;
//
//	std::cout << "Max of " << a << " and " << b << " is ";
//	std::cout << max<float >(a, b) << std::endl;	// explicit instantation.
//	std::cout << "Max of " << a << " and " << b << " is ";
//	std::cout << max(a, b) << std::endl;			// implicit instantation.
//
//	int	ret = max<int>(foo(a), foo(b));
//	std::cout << "Max of " << a << " and " << b << " is ";
//	std::cout << ret << std::endl;
//	return (0);
//}