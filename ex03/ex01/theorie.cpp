//
// Created by Kevin Di nocera on 11/4/22.
//

// ⚠️ [ctrl] + [cmd] + [space] = emojis ⚠️
/*	**	what is the difference between const and static ?!!
 * 		src => https://www.geeksforgeeks.org/difference-between-static-and-constant-function-in-cpp/
 *
 * 		constant:	function in constant guarantees that it will not allow modifying object or call any non-const member
 * 					function. it's a read-only function and does not modify the object for which is called.
 *
 *		static: 	it is a member function that access only static data member, he cannot access to non-static data member.
 *					it is also used to maintain a copy of the class member function across different objects of => classe.
 * */


/*	** les héritages what that ?!!!
 *
 * 		advantage: make the code clear and make it explicit. => it's use when a groupe of class need the same characteristic
 * 		but with exception => barbare need a dag, the archer need a bow.
 *		it's the capability of a class to derive his properties and characteristics from another class
 *		it's the process in which, new classe are created from the existing class
 *		- new class			-> derived or child class.
 *		- existing class	-> base or parent class.
 *		- derived			-> it's will say that the child class inherits all the properties of the parent class.
 *
 *		⚠️ the child class will not affect the base class
 *
 *		✅ when can I use it ?!!
 *
 *		ex:		consider a group of vehicles. -> Bus, Car, Truck ->
 * 				all 3 have the same properties: 1. fuelAmount();
 * 												2. capacity();
 * 												3. applyBrake();
 * 				if I make the same 3 functions, this increase the chance of errors and data redundancy.
 * 				to avoid this situation, inheritance(heritage) is used.
 *
 * 				I have now a parent classe with all the properties and 3 child class who inherited it.
 *
 * 		syntax of a derived / child class
 * 		→	class <derived_class_name> : <access-specifier> <base_class_name>
 * 			{	body...		}
 *
 * 		→	Ex:	💿 class ScavTrap : public ClapTrap {};
 *
 * 			explication:	access-specifier → private, public or protected. if neither is specified,
 * 							"private" is taken as default.
*
 * 		super class => A -> B -> C		=> 		C inherit from B and A 		=>	 	B inherit from A
 * */

// ⚠️ [ctrl] + [cmd] + [space] = emojis ⚠️
/*	**	what is the difference between const and static ?!!
 * 		src => https://www.geeksforgeeks.org/difference-between-static-and-constant-function-in-cpp/
 *
 * 		constant:	function in constant guarantees that it will not allow modifying object or call any non-const member
 * 					function. it's a read-only function and does not modify the object for which is called.
 *
 *		static: 	it is a member function that access only static data member, he cannot access to non-static data member.
 *					it is also used to maintain a copy of the class member function accross different objects of => classe.
 * */
