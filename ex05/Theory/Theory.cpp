//
// Created by Kevin Di nocera on 11/6/22.
//

/*
 * Nested class => is when you include a class in another class
 *
 * class	Vendredi
 * {
 * 		private:
 * 		public:
 * 			class	Matin
 * 			{
 * 				//[...]
 * 			};
 * 			class	ApresMidi
 * 			{
 * 				//[...]
 * 			};
 *
 * 	};
 *	class	Samedi
 * {
 * 		private:
 * 		public:
 * 			class	Matin
 * 			{
 * 				//[...]
 * 			};
 * 			class	ApresMidi
 * 			{
 * 				//[...]
 * 			};
 *
 * 	};
 * 	the class Matin and ApresMidi aren't the same in Vendredi and in Samedi.
 *
 * ----------------------------------------------------------------------------------------------------------------
 *
 * Exception:	2 types of errors:	1.	compilation errors - the detected errors during the compilation,
 * 										it's include a reference of library.
 * 									2.	execution errors - they are called "exception" to.
 *
 *									-	The exception is a problem during the execution of the program.
 *									-	The C++ exception is a response to an exceptionnel error during
 *										the execution of the program.
 *									-	All the exception are derived from the class std::exception.
 *										it's an execution error who can be manage.
 *
 *				Why manage the exception:	The principal advantage the manage of
 *											the exceptions has compared to the traditional version are:
 *
 *									-	The separation of the code and the errors managements code.
 *										⚬ Remove the condition if/else and make the code more readable.
 *
 *									-	The functions/methods can manage all the exceptions.
 *										⚬ Let the function call the exception for a better management of the errors.
 *
 *									-	Grouping errors types.
 *										⚬ Create a hierarchy between the exception object and regroup them.
 *
 * 				Management of exceptions:	Three keywords:	"Try" - "catch" - "throw => lever"
 *
 * 									-	try:	allow you to define a bloc of code to testing for
 * 												the errors during the execution.
 * 									-	catch:	Allow you to define a bloc of code to executing if an error
 * 												occurs in the bloc try.
 * 									-	throw:	"throw => lever" an exception when a problem is detected, allow you
 * 												to create a personalized error.
 * 				Exemple:			Syntaxe
 * 									❏	try
 * 										{
 * 											catch ( nameException e1 )
 * 											{
 * 												manage exception e1;
 * 											}
 * 											catch ( nameException e2 )
 * 											{
 * 												manage exception e2;
 * 											}
 *										}
 *
 *									⌲	you can list many instruction catch for different type of exceptions.
 *
 *				Throw exception:	The exceptions can be "throw => lever" with "throw"

 *									❏	the function below throw a exception when a division by zero occurs.
 *										double division( int a, int b )
 *										{
 *											if ( b == 0 )
 *											{
 *												throw "division par zero!";
 *											}
 *											return ( a / b );
 *										}
 *										int main(void)
 *										{
 *											std::cout << division ( 5, 0 ) << std::endl;
 *											return ( 0 );
 *										}
 *
 *										→ output
 *										⌲	terminate called after throwing an instance of 'char const*'.
 *
 *				intercepted a exception:	the bloc catch who follow the bloc try intercept all the exception.
 *											it can be specified which type must be intercepted => in ().
 *
 *										❏	syntaxe:
 *											 try { code protected }
 *											 catch( NameException e )
 *											 {
 *											 	code for manage the exception NameException e;
 *											 }
 *
 *										❏	bellow in the "code exemple n. 2" section the output is:
 *											|-----------------------|
 *											|	Division par zero!	|
 *											|	bye bye				|
 *											|-----------------------|
 *
 *										⚠️ 	if a exception is throw and is never intercepted the program terminates
 *											abnormally and display an errors. ⚠️
 *
 *				Exception in standard C++:	C++ provides a list of defined standard exceptions in std::exception.
 *											List of exceptions =>
 *											https://developpement-informatique.com/article/366/la-gestion-dexceptions-en-c++---declaration--utilisation-et-personnalisation
 *
 *
 * 										❏	We can define our self exceptions with inherit and substitute (surcharge)
 * 											the feature of the class std::exception => below an exemple how to use the
 * 											std::exception class for implement our own exceptions in the standard way.
 *
 * 										❏	bellow in the "code exemple n. 1" section the output is:
 *											|-----------------------|
 *											|	Division par zero!	|
 *											|	bye bye				|
 *											|-----------------------|
 *
 */

/* ----------------------------------------------------code exemple ---------------------------------------------------- */

//---------------------------------------------------- exemple 1 -------------------------------------------------------

#include <iostream>
#include <exception>

using namespace std;

class DivisionError : public exception{
public:
	virtual const char *what() const throw()
	{
		return "Division par zero!\n";
	}
};

double division( int a, int b )
{
	if( b == 0 ) {

		throw DivisionError();
	}
	return (a/b);
}

int main( void )
{
	int a = 5, b = 0, res;
	try
	{
		res = division( a, b );
		cout << "résultat de a/b = " << endl;
	}
	catch( DivisionError& e )
	{
		cerr << e.what() << endl;
	}
	cout << "bye bye";
	return 0;
}
//---------------------------------------------------- exemple 2 -------------------------------------------------------

//
//#include <iostream>
//
//using namespace std;
//
//double division( int a, int b )
//{
//	if( b == 0 ) {
//		throw "Division par zero!";
//	}
//	return ( a / b );
//}
//
//int main()
//{
//	int a = 5, b = 0, res;
//	try
//	{
//		res = division( a,b );
//		cout <<"résultat de a/b = " << endl;
//	}
//	catch( const char* msg )
//	{
//		cerr << msg << endl;
//	}
//	cout << "bye bye";
//	return 0;
//}

//---------------------------------------------------- exemple 3 -------------------------------------------------------

//void	test1()
//{
//	try
//	{
//		if (/*an ERROR exist*/)
//		{
//			throw std::exception();
//		}
//	}
//	catch (std::exception e)
//	{
//		// handle the error here
//	}
//}
//
//void	test2()
//{
//	if (/*an ERROR exist*/)
//	{
//		throw std::exception();
//	}
//	else
//	{
//		// do some stuff
//	}
//}
//
//void	test3()
//{
//	try
//	{
//		test2();
//	}
//	catch (std::exception &e)
//	{
//		// handle the error here
//	}
//}
//
//void	test4()
//{
//	class PExeption : public std::exception
//	{
//	public:
//		virtual const char *what() const throw()
//		{
//			return ("problem exists between keyboard and chair");
//		}
//	};
//	try
//	{
//		test3();
//	}
//	catch (PExeption &e)
//	{
//		//Handle the fact that the user is an idiot
//	}
//	catch (std::exception &e)
//	{
//		//handle other exception that are like std::exception
//	}
//}