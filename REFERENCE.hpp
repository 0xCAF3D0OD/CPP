
#include <iostream>
#include <string>

// if class aren't base or child →	class anotherClass

class	NameClass //: public/private baseClass
{
private:
	std::string _Atrib1;
	bool _Atrib2;
	int _Atrib3;

public:
	NameClass(void);
	NameClass(NameClass const &src);
	NameClass(std::string name, int number, bool vraiFaux);

	NameClass &operator=(NameClass const &rhs);

	NameClass	getAtrib1(void) const;
	std::string	getAtrib2(void) const;
	bool		getAtrib3(void) const;
	int 		getAtrib4(void) const;

	NameClass	setAtrib1(void) const;
	std::string	setAtrib2(void) const;
	bool		setAtrib3(void) const;
	int 		setAtrib4(void) const;

	~NameClass();
};