# Exception	
* **2 types of errors**	
 1. compilation errors - the detected errors during the compilation,it's include a reference of library.
 2.	execution errors - they are called "exception" to.

 → The exception is a problem during the execution of the program.

 → The C++ exception is a response to an exceptionnel error during the execution of the program.
								
 →	All the exception are derived from the class std::exception. It's an execution error who can be manage.

* **Why manage the exception**	
 
  The principal advantage the manage of the exceptions has compared to the traditional version are:
   * The separation of the code and the errors managements code.
   
      * Remove the condition if/else and make the code more readable.

   * The functions/methods can manage all the exceptions.
     * Let the function call the exception for a better management of the errors.
   * Grouping errors types.
     * Create a hierarchy between the exception object and regroup them.

* **Management of exceptions**	
 
  **Three keywords**:	"`Try`" - "`catch`" - "`throw` → lever"
     * try:	allow you to define a bloc of code to testing for the errors during the execution.
     * catch:	Allow you to define a bloc of code to executing if an error occurs in the bloc try.
     * throw:	"throw => lever" an exception when a problem is detected, allow you to create a personalized error.
                
* Exemple:			Syntaxe
*     try
      {
          catch ( nameException e1 )
          { 
             manage exception e1;
          } 
          catch ( nameException e2 )
          {
             manage exception e2;
          }
      }

     * you can list many instruction catch for different type of exceptions.

* **Throw exception**	The exceptions can be "`throw` → lever" with "`throw`"

  the function below throw an exception when a division by zero occurs.
*     double division( int a, int b )
      { 
         if ( b == 0 ) {
             throw "division par zero!";
         }
         return ( a / b ); 
      }
      int main(void)
      { 
         std::cout << division ( 5, 0 ) << std::endl; 
         return ( 0 ); 
      }

*       output:
         → terminate called after throwing an instance of 'char const*'.

* **intercepted an exception**	
 the bloc catch who follow the bloc try intercept all the exception. It can be specified which type must be intercepted → in `()`.

*     try { code protected }
      catch( NameException e )
      { 
         code for manage the exception NameException e;
      }

* in the Theory/Theory.cpp file, the `code exemple n. 2` code has this output is:
*     Division par zero!
      bye bye

 
  ⚠️ 	if an exception is throw and is never intercepted the program terminates abnormally and display an errors. ⚠️
 
* **Exception in standard C++**	
 
   C++ provides a list of defined standard exceptions in std::exception.


* **List of exceptions** →  ***developpement-informatique.com***
											

* We can define our self exceptions with inherit and substitute (surcharge)
the feature of the class std::exception.
 
→ How to use the std::exception class for implement our own exceptions in the standard way ?

* in the Theory/Theory.cpp file, the `code exemple n. 1` code has this output is:
* 
      Division par zero!	
      bye bye

## Reference

[developpement-informatique.com](https://developpement-informatique.com/article/366/la-gestion-dexceptions-en-c++---declaration--utilisation-et-personnalisation)