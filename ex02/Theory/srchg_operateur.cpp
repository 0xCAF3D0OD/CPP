//
// Created by Kevin Di nocera on 10/26/22.
//
#include <iostream>
/*
 * 	*	Polymorphisme Ad-hoc (surcharge d'opérateur):
 *		surcharge: the capacity to rename a function with the same name from a another and
 *		opérateur: the signe do you put after the name of the function; +, -, =, ==, +=, -=, etc. ... .
 *
 *		a + b	=>	can be write as a function; "operator+(a, b)" or a instance who call function operator; a.operator+(b), + is a operator;
 *		-a 	=>		can be write as a function;"operator-(a)" or a instance who call function operator; a.operator-(void), - is a operator;
 *		++a	=>		can be write as a function; "operator++(a)" or a instance who call function operator; a.operator++(void), ++ is a operator;
 *		std::cout << a =>	can be write as function; "operator<<(cout, a)" or a instance who call function operator; cout.operator<<(a);
 *		a = b	=>	can be only write as an instance who call function operator; a.operator=(b);
 *
 *		externe (outdoor the classe);	is when you call a function;	Complexe operator+(Complexe, Complexe) =>	"operator+(a, b)"
 *										ex: cout << z1 worth operator << (cout, z1);
 *										the prototype out the classe is;	ostream& operator<<(ostream&, complexe const&); Warning for the return the type of the function is required.
 *										you must put a '&' when you want modifie a value of a element;
 *		interne (indoor the classe);	is when you call the instance;	Complexe operator+(Complexe) const =>		"a.operator+(b)"
 *										how to know when you must use intern or extern: when you must modify value from the classe it's better to use the intern methode
 *										but when you don't modifie a value you can use the extern methode directly.
 *
 *	*	why "const integer operator+(integer, integer const&);" ?			it's block the possibility to modifie the result of a function.
 *
 *	*	why "ostream& operator<<(ostream& sortie, complexe const& z);" ?	it's the same as operator<<(cout << z1, endl); who is the same as operator<<(operator <<(cout << z1), endl); the second operator is
 *																			at the first place in the parameter so it must be the same type as the first argument "ostream& operator" it give the possibility to repeat the the "<<" operator.
 *																			Ex: std::cout << "je " << "suis " << "là" << std::endl; without "ostream& operator<<(ostream& sortie, ..." it impossible to repeat the process.
 *																			"permet la répétition d'appel à l'opérateur d'affichage"
 *
 *	*	which type for a += operator ?										if the type to return exist already, it will be important to use the same type
 *																			Ex:	complexe operator+=(complexe z1, complexe const &z2
 *																				z3 = z1 += z2	=> z3 take the result of z1 = z1 + z2 so z1 take the result of himself + z2, the result for z3 is the same as z1,
 *																				z1 has already a type complexe so for taking the same complexe you add a '&' => complexe& complexe::operator+=(complexe const& z2);
 *																				=> returning the value of the adresse it must return the "instance courante => pointeur sur adresse" => return *this
 *
 *	*	opérateur d'affectation (=)											"EnormeClasse& operator=(EnormeClasse const&) => a.operator=(b, c)" this is equivalent to a = b = c	=>	this is equivalent to a = (b = c); the classe exist already so
 *																			a and b is the same type; so the return value is the same type as the classe, so to avoid a new copy of a existant type we use the reference to use the existant type.
 *
 *																			/*	the problem with the flying point number is that the computer can't take a infinity of number the flying point number allow you
 *
 *
 *
 *
 *	What is a flying point number for the computer (nombre à virgule)?!!
 *
 *	-	The memory of the computer is limited when we talk about an real number or decimal number it exists an infinity of them.
 *		it' impossible to stock all the numbers.
 *
 *	What is a Whole number ?!!
 *
 *	-	the Whole number are the number who don't take a comma.
 *	-	In the computer we use a binary system (base 2 => 1 and 0)
 *
 *	To compact big number, it's easier for the computer to manage them. flying point consist of multiply 1 or 2 by power 2.
 *	the power is the "exposant", it's a number powered by 2: 10^2, 10^4, 10^6, 10^18, 10^32, etc. ... . he's size is 8 for 32 bits architecture and
 *	11 in 64 bits.
 *	for the mantisse => in 1,XXXXX * 10^(e) (e = exposant) the mantisse is the XXXXX party he is composed of 23 bits in a 32 bits architecture and
 *	52 bits in 64 bits.
 *	for a better understanding check this reference => https://www.redlab.io/le-monde-merveilleux-des-flottants/ .
 *
 *	"Roundf" return the integral value that is nearest to "(value * (1 << Fixed::_fractbits))"
/*	with halfway cases rounded away from zero. => avec des cas intermédiaires arrondis à partir de zéro.
/*	the return : The value of x rounded to the nearest integral (as a floating-point value).
 * */
class integer
{
public:
	integer(int const n);
	~integer();

	int		getvalue(void) const;
	integer	&operator=(integer const &rhs);
	integer	operator+(integer const &rhs) const;
private:
	int _n;
};

std::ostream  &operator<<(std::ostream & o, integer const & rhs);

integer::integer(int const n)
: _n(n)
{
	std::cout << "constructor =>	hello world:	" << _n << std::endl;
	return ;
}
integer::~integer()
{
	std::cout << "destructor =>	byby world:	" <<  _n << std::endl;
	return ;
}

int	integer::getvalue() const
{
	return (this->_n);
}

integer &integer::operator=(const integer &rhs)
{
	std::cout << "assignation operator called from =>	" << this->_n
	<< " to " << rhs.getvalue() << std::endl;
	this->_n = rhs.getvalue();
	return (*this);
}

integer integer::operator+(const integer &rhs) const
{
	std::cout << "assignation operator called from =>	" << this->_n
	<< " and " << rhs.getvalue() << std::endl;

	return (integer(this->_n + rhs.getvalue()));
}

std::ostream &operator<<(std::ostream &o, integer const &rhs)
{
	o << rhs.getvalue();
	return (o);
}

int main(void)
{
	integer	x(5);
	integer y(10);
	integer z(0);

	std::cout << "value of x: " << x << std::endl;
	std::cout << "value of y: " << y << std::endl;
	y = integer(12);
	std::cout << "value of y: " << y << std::endl;
	std::cout << "value of z: " << z << std::endl;
	z = y + x;
	std::cout << "value of z: " << z << std::endl;
	return (0);
}