//
// Created by Kevin Di nocera on 10/26/22.
//
#include <iostream>

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