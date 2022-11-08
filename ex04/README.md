# The polymorphism 
* ***The same code can automatically adapt to the type of data to which it applies.***
 Code that is written in a unifying way for all types of data.
  with the polymorphism the same code apply to different character can have different action,
  specific to each.


* ⚠️ reminder →	inheritance the "`child class`" inherit from the "`parent class`"
  
  All the Attribute/Methods (except constructor and destructor).
  
  **The type** the object from the "child class" can be affect to a variable
  from "parent class".
*                 Ex:	{  
                           Personnage	p;
                           Guerrier	g;

                           p = g;
                        }
 
    Inherit is transitive:
    "`magicien`" is a "`sorcier`" who is a "`Personnage`".

    **"The choice of the methods to be called is made during the execution of the program
     according to the real nature of the instance concerned"** EPFL videos;
     that depends on the dynamic link resolution.


* **What does it mean ?**	
  
  In c++ it's the type of the variable who determine the methode to execute;
 
  →	The static link resolution is when the standard call is called (when you add nothing more);
  
  →	The dynamic link resolution need to be called with "`virtual`",
    it must be called in the class "parent"
    * If the methode is called in the "child" so the methode exists as virtual.
    * In "parent" the methods is allowed because it exists already.

       * Virtual type:		In C++ Virtual indicate that the Methods is dynamic.

       * Virtual function/methods:	Member function call in "parent class" who's redefine in "child class".

* **In resume**		When the virtual methods is called from a reference or from a pointer to an
  "instance" it's the methods from the real type who is executed. Not the mammal but the dolphin who's called.

  ⚠️	
  
  →	It's strongly recommended to always define the destructor as virtual.
  
  →	A constructor can't be virtual.
  
  →  The aspect virtual is ignored by the methods in the constructor. ⚠️

# abstract class:	
 →	Is used to impose on the subclasses, that they must redefine the inherited virtual method.
					
 →	It's signaled as a `=0` at the end of the prototype.

 →	In general it's incompletely specified: it has no corps → no definition in the class.

 Abstract class is a class who content at less 1 virtual method pur.
 "Pur virtual function → `virtual void show() = 0`":
 
 →	Can't be instanced.
 
 →	The subclass stay abstract, as long as it does not provide the definitions from all the pure virtual
 methods inherited. As long, they don't delete the "`= 0`".
 
 If the "child class" redefine all the pur virtual methods => the "child class" isn't an abstract class
 any more, but if one of the pur virtual methods isn't redefine in the "child class", the class stay as
 an abstract class.
 
## Reference

[Polymorphisme : introduction](https://www.youtube.com/watch?v=vmBr7L7I3wo)