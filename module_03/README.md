#	what is the difference between const and static ?!!

* **constant**:	
  
  Function in constant guarantees that it will not allow modifying object or call any non-const member
  function. it's a read-only function and does not modify the object for which is called.

* **static**: 	
  
  It is a member function that access only static data member, he cannot access to non-static data member.
  it is also used to maintain a copy of the class member function across different objects of => classe.



# Inheritance what that ?!!!

* **advantage** 
  
  Make the code clear and make it explicit. => it's use when a groupe of class need the same characteristic
  but with exception => barbare need a dag, the archer need a bow.

  It's the capability of a class to derive his properties and characteristics from another class
  it's the process in which, new classe are created from the existing class
  - new class			-> derived or child class.
  - existing class	-> base or parent class.
  - derived			-> it's will say that the child class inherits all the properties of the parent class.

  - ⚠️ the child class will not affect the base class

## when can I use it ?!!

* **exemple**
  - Consider a group of vehicles. -> Bus, Car, Truck ->
  - All 3 have the same properties 
    1. fuelAmount();
    2. capacity();
    3. applyBrake();
 
    If I make the same 3 functions, this increase the chance of errors and data redundancy.
    to avoid this situation, inheritance(heritage) is used.
    I have now a parent classe with all the properties and 3 child class who inherited it.

    syntax of a derived / child class
  *      class <derived_class_name> : <access-specifier> <base_class_name>
         {	body...		}

  * type of class
  *      class ScavTrap : public ClapTrap {};

  explication:	access-specifier → private, public or protected. if neither is specified,
  "private" is taken as default.

   *     super class => A -> B -> C => C   inherit from B and A => B    inherit from A

# Ressources

[Difference between static and constant function in C++](https://www.geeksforgeeks.org/difference-between-static-and-constant-function-in-cpp/)
