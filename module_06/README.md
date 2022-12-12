# The Cast 
- 2 cast in c implicit and explicit
=> double b = a; implicit
=> double c = (double) a; explicit
- 2 type of comportement

## conversion
* An `int` **in the memory**: all the bits follow each other.
* For the `float` and `double`, **a part of the bits** are for exponent, another for mantis etc...
* `int` is **less precise than double**. when we pass a type from a **more precise** to a **less precise**, we **lose precision**.
**code for the int** and the `double` are **different**!

## reinterpretation
* **The hierarchy** must be respected → a **void is more general** than an `int`
* warning with the address

## Type qualifier reinterpretation
* `const` and `volatile` = **qualifier type**.
* **int const is more general** than an `int`.
* When you want to pass an **address from a const** to an `int`, **it's called a demotion**,
for managing a demotion, you must **cast the variable in int**.

## Upcast and downcast
* **new hierarchy** with the class in c++.
* **In example**, we have a **class `Parents`** and **two class `child`**, **the Parents class** is **less precise**
than the **child class**.
* With a `down cast` the implicit cast is **impossible**, **passing the value of Parents to the child**(who are more precise).
the **explicit cast is required**.
* **In the example** 
  * whe have **two child class**.
  * the **variable Parents "d"** take the **address from "a"**.
  * **a is the variable child1**. 
  * This cast is a **problem**, it will **compile**.
  * When we **cast "d" with child2** an **error can occur during the execution**, Because:
      1. we have two child class.
      2. the child2 class is not the same as child1.

## Static cast
* exemple: `static_cast<type>(variable to cast)`;
* The rules are the same as for upcast and downcast.

## Dynamic cast
* **Only cast** who occur **at the runtime**.
* **He can fail during execution** and not during compilation.
* the `Dynamic cast` can work only with a **polymorph instance**, one of the member function **must be virtual**.
* He can **only be used with a down cast** (value Parent to child) and verify if the cast is possible or not.
* He's **only** working on `pointer` and `references`, **the comportment is different** between `pointer` and `reference`.
* `Dynamic cast` **return the `address` or `NULL`**, `NULL` when the **conversion is impossible**.
* For the `dynamic cast` with a `reference` the result **can't** be `NULL` => so the try exception is required.
* If the **type who is cast** isn't **the real type** the `dynamic cast` will **return an error**. 

   → In the example **child2** receive a "**b**" `dynamic casted` with **child2** but "**b**" has received
   the **address from child1**, so the **program return an error**.
 
## Reinterpret cast
* **reinterpret** all the cast.
* He **compiles with an error** but at the execution it will **exist problems**.
* the commun use is when it must be a change of type.

## Const cast
* The **only cast** who can **cast the qualifier type**.
* `demotion` **is prohibited** with the `qualifier type`, the `const_cast<type>(variable)` let you do it.
* when you must use the `const_cast` it's maybe because the code isn't good wrote. 
* If you can avoid to use it changes you code, it's better. If you use a library who aren't good wrote use it.

## Explicit keyword
* built op 

## Cast operators
## Reference

[Polymorphisme : introduction](https://www.youtube.com/watch?v=vmBr7L7I3wo)