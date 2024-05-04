# Chapter 1: Compiled vs. Interpreted Programming Languages

## Section 1.1: Machine Code & Assembly

* A computer's CPU only understands a very limited set of basic instructions which are called *machine code* and it is written in binary. For instance, we can have: `10110000 01100001`.
* Because machine code is hard for us to read and understand, people invented *assembly language*, where each instruction is defined using a short abbreviation, and names and numbers can be used. FOr instance, we can have: `mov al, 061h`.
* A computer cannot directly understand assembly, and instead must have an *assembler* translate it into machine code.
* There is one issue with both machine code and assembly: because each CPU has a different set of instructions and thus neither machine code or assembly is very portable.

## Section 1.2: High-level languages

* Protability issues with machine & assembly are solved* with high-level languages such as C++, Python, Javascript, etc. These are designed to be very human readable and to be used in any kind of computer, regardless of the CPU's architecture.
* There are two types of high-level programming languages
  * Interpreted
    * E.g.: Python
    * There is a program called an *interpreter* which directly executes the instructions in the code without compilation.
    * Highly portable, but very inefficient.
  * Compiled
    * E.g.: C/C++
    * There is a program called a *compiler* which translates the source code into another, lower level language (e.g. assembly, machine code).
    * The compiled code is very efficienct compared to its interpreted counterpart.
* Higher-level languages makes programming far more accessible to a wider public. Remember the cryptic snippet of code in machine code and assembly seen in the previous section? Here is the exact same instruction, but in C++: `a = 97;`. You do not need to be a programmer to understand what that those!
* As an example of how compilers work, we can visit [godbolt.org](https://godbolt.org/) to see the end result of a compilation! Just copy the following code into the cell on the left, choose your favorite compiler, and see the results on the cell to the right.
  ```cpp
  #include <iostream> // Standard header file in system directory

  int main() {
      int n = 3;
      int m = 5;
      int sum = n + m;
      return 0;
  }
  ```
  We will discuss more about what code such as this does later on.

## Section 1.3: C++ vs. Python

* Despite Python and C++ being fundamentally different in that one is an interpreted language and the other is a compiled language, the knowledge you already have gathered from the former is very portable to this new context. However, there are some immediate practical differences we need to keep in mind.
  * In C++, you first need to compile your source code. This will produce an output executible which you can then run. In Python, you can just feed the source code into the interpreter and it will just run.
  * In Python, you can declare a variable like `a = 5`, and, through context, the interpreter will understand that `a` is supposed to be of type `int`. However, in C++ you need to explicitly tell the compiler what type of data a variable is supposed to represent. For example, to do the same assignment, we would need to do `int a = 5`.
  * Python and C++ are syntactically distinct. For instance, in C++, you need to finish every line of code with a `;`. We will see other differences later.
  * In C++, you have more direct access to memory, while in Python this is mostly taken care of behind the scenes.

## Section 1.4: Compiling C++ Source Code

* Compilation of source code is only the first step in the construction of executable software from source code.
* Overview of *building* processs
  * The compiler checks that the input C++ code is well written and does not have any syntactical errors.
  * The compiler translates the C++ code into machine language instructions. This produces an object file (`.obj` or `.o`) for each input file.
  * The *linker* combines all of the object files, ensuring all cross-file dependencies are resolved properly, and linking library files. This almost always includes the *C++ Standard Library* which provides some basic libraries such as the *iostream library*.
  * You finally have an executable file you can run.
* Let's compile our first C++ code. First open [helloworld.cpp](/examples/helloworld.cpp) with your favorite text editor (can you guess what it does)? Next, exit the editor and run the following command.
  ```bash
  g++ helloworld.cpp -o helloworld
  ```
  This will produce a new file called `helloworld`. This is the output of the compilation process. To run it just run `./helloworld` in the terminal.

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

## Section 2.2: Variables

* In Python, to declare a variable of type `int`, you can just write `x = 5` and the interpreter will take care of deciphering what type `x` should be. However, in C++, you need to explicitly say what type the variable will be at the time of declaration. For instance, to define the same variable in C++, we would need to write `int x = 5;`.
* You can also declare a variable without initializing it. For instance, you could just write `int x`. But what value will `x` have? 


---

# Variables & Types

* LIKE Python, each variable needs a name to identify it. In order for an identifier to be valid it must obey the following conditions:
  * It must be a sequence of one or more letters, digits, or underscore
  * It must NOT include spaces, punctuation marks & symbols
  * It must ALWAYS begin with letter or underscore (though the latter is usually reserved for special purposes)
  * It must NOT be one of the reserved keywords in C++
* Note that C++ identifiers are case sensitive
* UNLIKE Puython, each variable must have a data type when it is declared
  * Although all data will be stored somewhere in RAM as a series of 1's and 0's, the amount of memory taken by one data type might be different to another, and the bits will be interpreted differently depending on what they are said to represent.
* Here are the base data types, also called arithmetic types:

| Group of types         | What they store               | Type names | Notes |
| ---------------------- | ----------------------------- | ---------- | ----- |
| Character types        | Represents a single character | char       |       |
|                        |                               | char16_t   |       |
|                        |                               | char32_t   |       |
|                        |                               | wchar_t    |       |
| Integer types (signed) |                               |            |       |

* Simple use example of vairables

  ```cpp
  // operating with variables

  #include <iostream>
  using namespace std;

  int main ()
  {
  // declaring variables:
  int result; // uninitialized variable

  // process:
  int a = 5; // initialized variable
  int b = 2; // initialized variable
  a = a + 1;
  result = a - b;

  // print out the result:
  cout << result;

  // terminate the program:
  return 0;
  }
  ```
* There are strings in C++ just like in Python, but we must first include `string`, which is part of the standard library. For example

  ```cpp
  // my first string
  #include <iostream>
  #include <string>
  using namespace std;

  int main ()
  {
  string mystring;
  mystring = "This is a string";
  cout << mystring;
  return 0;
  }
  ```

  * `string` class is a compound type. Compound types can be used in the same way as fundamental types (they use the same syntax to declare and initialize)
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
* In string literals & chars, there are special characters that are used through the use of an escape code which starts with `\`. The following tables describes these

| Escape code | Description           |
| ----------- | --------------------- |
| `\n`      | newline               |
| `\r`      | carriage return       |
| `\t`      | tab                   |
| `\v`      | vertical tab          |
| `\b`      | backspace             |
| `\f`      | form feed (page feed) |
| `\a`      | alert (beep)          |
| `\'`      | single quote          |
| `\"`      | double quote          |
| `\?`      | question mark         |
| `\\`      | backslash             |

* You can also define contants. For example

  ```cpp
  #include <iostream>
  using namespace std;

  const double pi = 3.14159; // global contant
  const char newline = '\n'; // global constant

  int main ()
  {
  double r = 5.0;               // radius
  double circle;

  circle = 2 * pi * r;
  cout << circle;
  cout << newline;
  }
  ```
* Another way of naming constant values is with the use of preprocessor definitions. The syntax is `#define identifier replacement`. When the preprocessor finds this, it will know to blindy (i.e. not checking type validity) replace any occurance of `identifier` in your code with `replacement`.

  ```cpp
  #include <iostream>
  using namespace std;

  #define PI 3.14159
  #define NEWLINE '\n'

  int main ()
  {
  double r = 5.0;               // radius
  double circle;

  circle = 2 * PI * r;
  cout << circle;
  cout << NEWLINE;

  }
  ```

# Operators

* Assignment operato: `=`

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

* They serve the same purpose as in Python. The syntax to define one in Python is `type name (type parameter1, type parameter2, ...) {statements}`

  * `type` before name -> type of the value returned by the function. `void` if nothing is returned
  * `type` before parameters -> type of the n'th parameter of the function
  * Example:
    ```cpp
    #include `<iostream>`
    using namespace std;

    int subtraction (int a, int b) {
    int r;
    r=a-b;
    return r;
    }

    int main () {
    int x = 5, y = 3, z;
    z = subtraction (7,2);
    cout << "The first result is " << z << '\n';
    cout << "The second result is " << subtraction (7,2) << '\n';
    cout << "The third result is " << subtraction (x,y) << '\n';
    z= 4 + subtraction (x,y);
    cout << "The fourth result is " << z << '\n';
    }
    ```
* Note that `main` function has a return which is optional. If excluded it will be implied and added by the compiler. A return values of 0 by `main` means the program completed succesfully.
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

| Expression | What is evaluated                                | Equivalent |
| ---------- | ------------------------------------------------ | ---------- |
| `a.b`    | Member `b` of object `a`                     |            |
| `a->b`   | Member `b` of object pointed to by `a`       | `(*a).b` |
| `*a.b`   | Value pointed to by member `b` of object `a` | `*(a.b)` |

<!-- # Other Data Types -->

# Classes

# Special Members

# Friendship and inheritance

<!-- # Polymorphism -->

# Credit

These notes were developed using the material found in [https://cplusplus.com/doc/tutorial/](https://cplusplus.com/doc/tutorial/)
