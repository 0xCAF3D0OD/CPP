//
// Created by Kevin Di nocera on 11/7/22.
//

#include "Data.hpp"

Data::Data(void)
:	_i(0), _flt(0.0)
{
//	std::cout << "scal constructor is called" << std::endl;
}

Data::Data(int i, float flt)
:	_i(i), _flt(flt)
{
//	std::cout << ret << " scal constructor is called" << std::endl;
}

Data::Data(const Data &src)
{
	*this = src;
}

Data &Data::operator=(const Data &rhs)
{
	this->_i = rhs._i;
	this->_flt = rhs._flt;
	return (*this);
}

uintptr_t Data::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Data::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int Data::get_i()
{
	return (this->_i);
}

double Data::get_flt()
{
	return (this->_flt);
}

Data::~Data()
{
//	std::cout << "scal destructor is called" << std::endl;
}
