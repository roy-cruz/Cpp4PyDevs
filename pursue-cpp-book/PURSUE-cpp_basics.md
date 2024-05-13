

# Chapter 2: C++ Fundamentals

## Section 2.1: Hello World

* Let's use the example code used at the end of the previous chapter to discuss some C++ fundamentals. 
  ```cpp
  /*
  This is a multi-line comment.
  */
  #include <iostream>

  int main()
  {
    // This is an in-line comment.
    std::cout << "Hello world!";
    return 0;
  }
  ```
  * `#include <iostream>`: This is a preprocessor directive. Think of this as `import` in Python. In this case its "importing"`iostream`, which is part of the standard library and includes tools to read and write text to/from the console.
  * `int main()`: This line tells the compiler we are going to define a function with the name/identifier `main` which will return a value of type `int`. The `main` function is special, as every time you run code in C++ it starts there. **Every C++ program must have `main`.**
  * `{...}`: These are used to enclose a series of statements (i.e. a type of instruction that makes the program do something).
  * `std::cout << "Hello world";`: This is a statement and it is the C++ equivalent of `print()`. `std::cout` and the `<<` operator takes the string on the left and displays it on the console. Note that in C++, **all statements must end in a `;`**. This indicates to the compiler that that is the end of that particular statmenet.
  * `return 0;`: This is the same as the `return` in a python function and it indicates what the function will return once it is executed. In C++, if `main` returns 0, this is interpreted to mean that the program ran with no problems. Returning anything else is usually used to indicate that there was some issue with the execution of the program.

## Section 2.2: Variables & Constants

* In Python, to declare a variable of type `int`, you can just write `x = 5` and the interpreter will take care of deciphering what type `x` should be. However, in C++, you need to explicitly say what type the variable will be at the time of declaration. For instance, to define the same variable in C++, we would need to write `int x = 5;`.
  * Although all data will be stored somewhere in RAM as a series of 1's and 0's, the amount of memory taken by one data type might be different to another, and the bits will be interpreted differently depending on what they are said to represent.
* When you declare a variable of type `int`, for example, the computer allocates/reserves 4 bytes of memory for it. Note that different data types can occupy different amount of memory, so the amount allocated can vary.
* You can also declare a variable without initializing it. For instance, you could just write `int x;`. But what value will `x` have? If you run [noinit.cpp](/examples/noinit.cpp), depending on your setup, its likely that the result is 0. In practice, however, the default value is whatever happened to be in the space of memory allocated for the variable, which is generally junk! This can introduce unexpected behavior and bugs.
* ***Include discussion about different types of initializations?***
* Just like in Python, where there are names such as `print` or `return` you should not give to your variables as they are special *keywords* used by the language, C++ has its own set of keywords. You can read about them [here](https://en.cppreference.com/w/cpp/keyword).
* In order for an identifier to be valid it must obey the following conditions:
  * It must be a sequence of one or more letters, digits, or underscore
  * It must NOT include spaces, punctuation marks & symbols
  * It must ALWAYS begin with letter or underscore (though the latter is usually reserved for special purposes)
  * It must NOT be one of the reserved keywords in C++
* Note that C++ identifiers are case sensitive.
* Now that we know a bit about variables, we can go ahead and use them. Run example [varsexample.cpp](/examples/varsexample.cpp)
  ```cpp
  #include <iostream>
  
  int main() {
    int First_Number = 2;
    int Second_Number = 4;
    int Third_Number = First_Number + Second_Number;

    std::cout << "First Number + Second Number" << Third_Number;
  }
  ```
  * `First_Number`, `Second_Number` and `Third_Number` are variables of type `int`. Notice that, unlike in Python, the type *must* be specified.
  * When we go to define `Third_Number`, the right hand side of the expression is evaluated first, and its result is then assigned to `Third_Number`.
* You can also define contants. For example

  ```cpp
  #include <iostream>
  using namespace std;

  const float pi = 3.14; // global contant

  int main ()
  {
    float r = 5.0;               // radius
    float circle;

    circle = 2 * pi_according_to_engineers * r;
    cout << circle << "\n";
  }
  ```
* Another way of naming constant values is with the use of preprocessor definitions. The syntax is `#define identifier replacement`. When the preprocessor finds this, it will know to blindy (i.e. not checking type validity) replace any occurance of `identifier` in your code with `replacement`.

  ```cpp
  #include <iostream>
  using namespace std;

  #define PI 3.14

  int main ()
  {
    float r = 5.0;               // radius
    float circle;

    circle = 2 * PI * r;
    cout << circle;
    cout << NEWLINE;
  }
  ```

* Despite needing to specify the type at the time of declaration, it is possible to have the compiler deduce the type. For example:

  ```cpp
  int var = 0;
  auto var2 = var // Type is that of the value used to initialize it (i.e. int)
  ```
* In addition, you can give a variable a type based on the type of another variable as follows:

  ```cpp
  int var = 0;
  decltype(var) var2; // Same type as var
  ```
* Type deduction features should only be used if there is no other way to obtain the type, or to improve the readability of the code.

## Section 2.3: Types
* C++ has some familiar types which we have already seen, namely `int` and `float`. However, it also has a whole assortment of types which you may have not heard about. In the following table, we summarize these fundamental types for you:

|    Types    |    Category    |             Meaning             | Example | Size  |
| :---------: | :------------: | :-----------------------------: | :-----: | :---: |
|    float    | floating point | a number with a fractional part | 3.14159 |       |
|   double    |                |                                 |         |       |
| long double |                |                                 |         |       |
|    bool     |    boolean     |          True or False          |  True   |       |


| Group of types         | What they store               | Type names | Notes |
| ---------------------- | ----------------------------- | ---------- | ----- |
| Character types        | Represents a single character | char       |       |
|                        |                               | char16_t   |       |
|                        |                               | char32_t   |       |
|                        |                               | wchar_t    |       |
| Integer types (signed) |                               |            |       |



## Section 2.3: `iostream`

* Before we continue, lets take some time to understand `iostream` a little better, as it will serve as a useful library to build our understanding upon as we move forward.
* `iostream` (or the input/output library) is part of the C++ standard library and it offers tools that help with basic input (e.g. from your keyboard) and output (e.g. to your terminal) of data.
* This library offers classes such as:
  * `std::cout`: Allows us to print data into the terminal as text.
  * `std::cin`: Queries the user to input data from their keyboard into the terminal.
* We already saw an example of how to use `std::cout`, so lets see how `std::cin` is used. For the former, we saw that we needed to use the *insertion operator* `<<`. For the latter, we use the *extraction operator* `>>`. To run the following example, compile and run [nameio.cpp](/examples/nameio.cpp)
```cpp
#include <iostream>

int main() {
    // Ask user for their age
    std::cout << "How old are you?\n";
    
    // Get user's age
    int age = 0;
    std::cin >> age;

    // Print a response depending on the input.
    std::cout << "I see! So you're " << age << " years old!\n";
}
```

* In string literals & chars, there are special characters that are used through the use of an escape code which starts with `\`. The following tables describes these

| Escape code | Description           |
| ----------- | --------------------- |
| `\n`        | newline               |
| `\r`        | carriage return       |
| `\t`        | tab                   |
| `\v`        | vertical tab          |
| `\b`        | backspace             |
| `\f`        | form feed (page feed) |
| `\a`        | alert (beep)          |
| `\'`        | single quote          |
| `\"`        | double quote          |
| `\?`        | question mark         |
| `\\`        | backslash             |

## Section 2.4: Operators

* C++ shares many operators with Python. For instance, in C++ we have addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`), assignment (`=`), as well as comparion operators such as `==`, `<=`, `>=`, `!=`.
* We have seen two operators which are *not* found in Python, namely the insertion `<<` and extraction `>>` operators.
* There are also operators in C++ which are keywords. For instance, we have
  * `new`: Dynamically allocated memory for an object or an array of object of a given type and returns a pointer to the first byte of the allocated memory.
  * `delete`: Deallocates memory that was previous allocated by `new`. Also calls the destructor of the object before freeing the memory.
  * `throw`: Used to signal that an exceptional condition (e.g. an error) has occurred in the program.

* Assignment operator: `=`
  * Assigns a value to a variable
  * Left to right (always)
* Arithmetic operators: `+, -, *, /, %`

  * Same as python
* Compound assignment: `+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=`

  * Modify the current value of a variable by performing an operation on it.
  * E.g.: `y += x;` is equivalent to `y = y + x;`
* Increament and decrement: `++, --`

  * Note that these can go before or after a variable name. Although it is mostly equivalent, in some cases there is a difference. For example:

    ```cpp
    x = 3;
    y = ++x; // x if incremented first, then the new value is assigned to y
    //---------
    x = 3;
    x = x++; // y is assigned the current value of x, and then x is incremented
    ```
* Relational and comparison operators: `==, !=, >, <, >=, <=`

  * Same functionality as python
* Logical operators: `!, &&, ||`

  * `!` -> NOT boolean opeator
  * `&&` -> AND, `||` -> OR
* Conditional ternary operator: `?`

  * It is a conditional operator which evaluates an expression and returns one thing if the expression is `true` and another if it `false`
  * Syntax: `condition ? result1 : result2`
* Comma operator: `,`

  * Separates two or more expressions that are included where only one is expected. The expressions are evaluated left to rigth and only the rightmost expression is passed.
  * E.g.: In `a = (b = 3, b + 2);`, `b` is set to 3, and then `b + 2` is assigned to `a`.
* Bitwise operators: `&`, `|`, `^`, `~`, `<<`, `>>`

  * `&` -> Bitwise AND
  * `|` -> Bitwise OR
  * `^` -> Bitwise XOR
  * `~` -> Bit inversion
  * `<<` -> Shift bits left
  * `>>` -> Shift bits right
* Explicit type casting

  * Can be used to convert a value of one type to another
  * E.g.: Suppose `f` is a float. Then, in `i = int (f);`, `f` is converted to an integer and the result is assigned to `i`
* `sizeof`

  * Returns the size in bytes of a type or object
  * `x = sizeof (char);` returns 1, because `char` is a type of size 1 byte
* Operator precedence

  * (Table describing operator precedence)

## Section 2.5: Namespaces

## Section 2.6: Functions

* Just like in Python, a function in C++ is a reusable sequence of statements (ideally) designed to do a single job.
* They provide a way for us to split into modular, optimized chunks as well as a way to avoid writting the same code over and over.
* The syntax of functions in C++ is as follow:
  ```
  <return_type> <identifier>(arg1type arg1, arg2type arg2, ...) {
    <statements>
    .
    .
    .
    return <value_to_return>
  }
  ```
  * *Function header explanation*
  * There is more to say about how arguments are passed to a function in C++, but we will discuss that later.
* In C++, functions *must* be either be declared before they are used or must at least have their header located before the function itself is used. For instance, we could have
  ```cpp
  int foo() {
    ...
  }

  int main() {
    ...
    foo();
    ...
    return 0;
  }
  ```
  but the following would still work
  ```cpp
  int foo();

  int main() {
    ...
    foo();
    ...
    return 0;
  }

  int foo() {
    ...
  }
  ```
  Although the latter way of doing things might seem redudant, it can actually be very useful when it comes to code organization.
* Just like in Python, functions in C++ may or may not return something. In addition, in order to return something, we would use the same keyword, namely `return`. Its important to note, however, that unlike Python, the return type is something that is fixed at the function definition. Recall that when we write the header of a function, we have to specify the return type. For instance, `int foo()` means that `foo` will return a value of type `int`. In fact, if you have two functions with the same name, but with different return types, C++ will consider them separate functions. This is called *function overloading*.
* Function overloading is possible because the compiler will differentiate between functions of the same name by their return type and the parameter types. For instance, the compiler will consider `int foo(int par1, char par2)` distinct from `float foo(float par1, chat par2)`.
* In the case where a function does not return any value, you would not need to include a `return` statement and, as the return type you would put `void` in order to indicate the lack of any return values to the compiler. Alternatively, you could put an empty `return` statement, though this would be redundant.
* A function that returns a value can only return a single value back per call.
* To demonstrate the basics of how functions work in C++, lets write a `print()` function to have our code look a bit more like Python's. Take a look at [printfunct.cpp](/exampples/printfunct.cpp) (reproduced here). Compile and run it. This example contains many fundamental elements of functions in C++, as well as some new elements we have not seen before, so we will go step by step.

  ```cpp
  #include <iostream>
  #include <string>

  void print(std::string txt);
  int intprod(int int1, int int2);

  int main() {
      int int1 = 0;
      int int2 = 0;
      
      print("Input two numbers.\nNumber 1: ");
      std::cin >> int1;

      print("Number 2: ");
      std::cin >> int2;

      int prod12 = intprod(int1, int2);

      print("\nProduct of these two numbers: ");
      print(std::to_string(prod12));
      print("\n");
  }

  void print(std::string txt) {
      std::cout << txt;
  }

  int intprod(int int1, int int2) {
      return int1 * int2;
  }
  ```
  * In addition to including `iostream`, we are also including `string` here. While not strictly neccesary, as we could have used a list of `char`s for this, using `string` allows us to *Exmplanation about strings vs chars*



<!-- ## Section 2.4: Literals

* Whereas variables can have their values changed throughout the execution of some code, literals are fixed values that are inserted straight into the source code. For instance, in the following example the first `10` is a literal, whereas, `x` is a variable which happens to have the value `10`
```cpp
#include <iostream>

int main() {
  std::cout << 10 << "\n";

  int x = 10;
  std::cout << x << "\n";

  return 0;
}
```
* The main way to differentiate one from the other is that, for variables, the value needs to be fetched from memory first, but for the literal the value is hard-coded into the source code. -->


## Exercises:
1. Create a program that asks the user to enter an integers, waits for them to input an integer, then tells them waht 2 times that number is.
1. Modify the program from the previous exercise so that it also outputs what 3 times the given number is.
<!-- 1. Advanced: Define a function which computes the product of two numbers and use it to implement the code of the previous exercise. -->

# Chapter 3: Control Flow

# Chapter 4: 

## Section 4.1: Pointers & Dynamic Memory

## Section 4.1: Functions (Cont.)

* *Local scope*
* *Pass by value and by reference*


---

# Statements and flow control

* If and else

  * If a condition is fulfilled, the statement or block is executed
  * Syntax:
    ``cpp if (condition) statement ``

    * E.g.:

      ```cpp
          if (x == 100) {
              cout << "x is 100";
          }
      ```
  * `else` keyword can be used to introduce an alternative statement.
  * Syntax:
    ``cpp if (condition) statement1 else statement2 ``
  * E.g.:
    ``cpp if (x == 100) { std::cout << "x is 100"; } else { std::cout << "x is not 100"; } ``
  * There also exists the equivalent of `elif` from Python. It is done as follows:
    ``cpp if (x > 0) cout << "x is positive"; else if (x < 0) cout << "x is negative"; else cout << "x is 0"; ``
* The main loop structures in C++ are

  * `while (condition) statement;`
    * Repeats the statement while the expression is true
    * The first time the program encounters this loop, it first evaluates the condition and then the statemenet (if the condition is true)
  * `do statement while (condition);`
    * Same as the previous one, but the statement is evaluated first when the loop is first encountered, and then the condition is checked
    * Preferable when the statement needs to be performed at least once.
  * `for (initialization; condition; increase) statement;`
    * At first, the initialization is executed. Then, if the condition is true, the statement is evaluated. If, after the increase updates the condition, the condition is still true, the statement is executed once again. This repeats until the condition is false.
  * `for (declaration : range) statement;`
    * Iterates over all element in range.
    * declaration is some variable able to take the value of an element in this range
* You can also control the flow of your code with `continue` and `goto`

  * `continue`
    * Causes the program to continue the rest of the loop in the current iteration.
    * Placed inside another loop
  * `goto`
    * Jumps to a destination point identified by a label. Not very useful in modern paradigms

      ```cpp
          // goto loop example
          #include <iostream>
          using namespace std;

          int main ()
          {
              int n = 10;
          mylabel:
              cout << n << ", ";
              n--;
              if (n>0) goto mylabel;
              cout << "liftoff!\n";
          }
      ```
* Selection statement: `switch`

  * Used to check for a value among a number of possible constant expressions.
  * Like `if-else`, but limited to contant expressions.
  * Syntax

    ```cpp
        switch (x) {
            case 1: // Executed if x == 1
                cout << "x is 1";
            case 2: // Executed if x == 2
                cout << "x is 2";
            default: // If the other cases fail, it defaults to this one
                cout << "x has a value which is neither 0 or 1";
        }
    ```

# Functions

* There are two ways to pass arguments to a function: by reference or by value.

  * By value:
    * When calling the function, what is passed are the values of the arguments, which are *copied*. Any modification of the parameter variables in the function has no effect on the values of the variables passed outside it.
    * Syntax the same seen above
  * By reference
    * Allows access to an extenal variable withing a function.
    * In order to do this, what is passed is the *reference* (i.e. location in memory) of the variable.
    * Function declares its parameters as references by adding `&` following the parameter type
    * When passed by reference, what is passed is not a copy of the variable, but the variable itself (i.e. its location in memory).
    * Syntax is as follows:

      ```cpp
          // passing parameters by reference
          #include <iostream>
          using namespace std;

          void duplicate (int& a, int& b, int& c)
          {
          a*=2;
          b*=2;
          c*=2;
          }

          int main ()
          {
          int x=1, y=3, z=7;
          duplicate (x, y, z);
          cout << "x=" << x << ", y=" << y << ", z=" << z;
          return 0;
          }
      ```
* Functions parameters can have default values or optional parameters, just like in python. This is done by assigning a value to the parameter in the function definition of its parameters. We could call the following functions as `divide(x)` or as `divide(x, y)`

  ```cpp
      int divide (int a, int b = 2) {
          ...
      }
  ```

# Headers

# Arrays

* An array is a series of elements of the same type (and thus each occupying the same amount of memory) in a conttigous memory location. Each of them can be referenced with an index. They are similar to lists in Python.
* Uninitialized declaration: `int arr [n]`, where `n` is the number of elements
* Initialized declaration: `int arr [5] = { a, b, c, d, e}`
* You can declare an array without explicitly specifying the number of elements as well: `int arr [] = {a, b, c, ...}`
* To acces the values of an array, you use the index (starting at 0) of the element you wish to get. For example:

  ```cpp
      int arr [] = {14, 13, 12, 11, 10}
      x = arr[2] // value 12 is copied and assiged to variable x
  ```
* Warning: It is possible to use an index higher than the number technically allowed, but this can create issues as you are accesing data beyond that which was allocated for the array.
* You can create multi-dimensional arrays by adding more indices. For example, `int multidarr [n][m]` creates an array that has n*m elements. In order to access any of these elements, you use two indices. So, if we wanted element at position (1, 3), we would do `multidarr[1][3]`.
* Note that multi-dimensional arrays can have an arbitrary number of dimensions, not just two.
* Arrays cannot be passed by value. You can only pass the pointer (memory address) of it. Because the information of how long the array is is not a part of the array definition (like it is in lists in Python), you need to pass lenth of the array as well to avoid going out of range in any iteration. For example:

  ```cpp
      // arrays as parameters
      #include <iostream>
      using namespace std;

      void printarray (int arg[], int length) { // length of arg is not specified
      for (int n=0; n<length; ++n)
          cout << arg[n] << ' ';
      cout << '\n';
      }

      int main ()
      {
      int firstarray[] = {5, 10, 15};
      int secondarray[] = {2, 4, 6, 8, 10};
      printarray (firstarray,3);
      printarray (secondarray,5);
      }
  ```
* There exists a library called array which provides an array class which works much more like the lists and arrays in Python. (EXPAND)

# Pointers

<!-- # Dynamic memory -->

# Data Structures

* A data structure is a group of data elements (members) grouped unser one name. These members can have different types.
* Declaration syntax

  ```cpp
      struct type_name {
          member_type1 member_name1;
          member_type2 member_name2;
          ...
      } 
  ```
* With a struct definition, we can declare objects of the this type and access any of its members with a familiar `.` notation. For example:

  ```cpp
      struct person {
          int age;
          string profession;
      };

      person Andrew
      Andrew.age = 87
      Andrew.profession = "Climatologist"
  ```
* If you have a pointer to a structure instance, lets say `point_person = &Andrew`, if you want to access the member directly from this, you can use the deference operator

  ```cpp
      point_Andrew = &Andrew
      point_Andrew->age = 86 // Age changed from 87 to 86
  ```
* In terms of operator for pointers and for structure members, this table summarizes everything

| Expression | What is evaluated                            | Equivalent |
| ---------- | -------------------------------------------- | ---------- |
| `a.b`      | Member `b` of object `a`                     |            |
| `a->b`     | Member `b` of object pointed to by `a`       | `(*a).b`   |
| `*a.b`     | Value pointed to by member `b` of object `a` | `*(a.b)`   |

<!-- # Other Data Types -->

# Classes

# Special Members

# Friendship and inheritance

<!-- # Polymorphism -->

# Credit

These notes were developed using the material found in [https://cplusplus.com/doc/tutorial/](https://cplusplus.com/doc/tutorial/)
