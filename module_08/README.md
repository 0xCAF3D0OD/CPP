# The C++ Standard Template Library
## definition
* _**The standard Template library (STL)** is an ensemble of classe in C++, they provide programming data structures and functions
such as lists, stacks, arrays, etc... . it's a class of containers, algorithms and iterator. It's a generalized library and
it's components are parameterized._
* **Has 4 components**

<img src="https://d1m75rqqgidzqn.cloudfront.net/wp-data/2021/03/23180546/23-1024x332.png" width="500">

## Algorithms
* The header Algorithm define a collection of functions, they are specifically used of a range of elements. They act of
containers.

![](img/algorithm-1.jpg)

* **Algorithm**

  * **Non mutating algorithms** → The algorithms that are known **to not modify** with any value of **a container object** and 
  they have nothing to do with the change in order of the elements in which they appear.
  These algorithms **are used for all the container objects and the real use of** the **forward iterators** is made by them only.
  * **Mutating algorithms** → The algorithms that **can be generally used to modify the value of a container** and have the
  **authority to change the order of the elements** in which they appear.
  * **Sorting algorithms** → The **modifying algorithms that are used to sort the elements in a container**.
  * **Set algorithms** → The algorithm that is generally **used to execute some functions on a container** that 
  results in improving the efficiency of a program. **Another name** by which this algorithm is known is **sorted range algorithm**.


* **Numeric Algorithm**
  * Relational algorithms : The algorithms that are generally **used to work on the numerical data**. These algorithms are 
  **designed mainly to execute the mathematical operations over all the elements that are present in a container**.

## Containers
Containers or container classes **store objects and data**. There are **seven standards “first-class”** container classes, 
**three container adaptor classes** and only **seven header files** that **provide access to these containers** or container adaptors.


 | container          | Description                                                                                                                                     | header file | iterator      |
|:-------------------|:------------------------------------------------------------------------------------------------------------------------------------------------|:------------|:--------------|
 | vector             | **Generally** a C++ classe,<br/>used to **create dynamics <br/>array** that **allow**<br/>the **insertion** and<br/>**deletion** at the back.   | < vector >  | random access |
 | list               | Is the sequence containers<br/>that allow the insertion and<br/>deletion from anywhere.                                                         | < list >    | Bidirectional |
 | deque              | The double ended queue<br/>that allow the insertion and<br/>deletion from both ends.                                                            | < deque >   | Random access | 
 | set                | An associate container that<br/> are used for storing<br/>unique sets.                                                                          | < set >     | Bidirectional |
 | multiset           | An associate container that<br/> are used for storing<br/>non unique sets.                                                                      | < set >     | Bidirectional |
 | map                | An associate container that<br/> are used for storing unique<br/>key value pair, and<br/>each key can be associated<br/>with only 1 value.      | < map >     | Bidirectional |
 | multimap           | An associate container that<br/> are used for storing unique<br/>key value pair, and<br/>each key can be associated<br/>with more than 1 value. | < map >     | Bidirectional |
 | stack              | Stack generally follow<br/>the last in first out (LIFO).                                                                                        | < stack >   | No iterator   |
 | queue              | Queue follows first in first<br/>out (FIFO)                                                                                                     | < queue >   | No iterator   |
 | Priority<br/>queue | The first elements that is out<br/>is always of the highest<br/>priority level                                                                  | < queue >   | No iterator   |

[ ![](img/schemB1.png) ](![](img/schemB2.png))
[ ![](img/schemL1.png) ](![](img/schemL2.png))

## Reference

[Créez des templates](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7533236-creez-des-templates)

[Templates in C++ with Examples](https://www.geeksforgeeks.org/templates-cpp/)

[Template Specialization in C++](https://www.geeksforgeeks.org/template-specialization-c/)