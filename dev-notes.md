# Set Up
* We will be using GitHub codespace. Go to the repository of this tutorial and press ".". This will inititate a codespace which includes a compiler we can use.
* We will also be using [goldbolt](https://godbolt.org/) to see the output of the compiler for some simple examples.

# Compilers
* Computers only understand machine language which is composed of 1's and 0's. It is possible to write your programs in this language, but it is extremely tedious. Therefore, higher level programming languages have been developed which allow the instructions you pass to your computer to be more human readable. 
* In order to translate between the human-readable higher level languages and machine code, we use programs called compilers, interpreters or assemblers.
* C++ is a compiled language, which means that before your code can be executed, it first needs to be translated into something closer to the computer's "natural language". This is done with compilers.
* Here is a simple example. Copy and paste this block of code in its entirety into [goldbolt](https://godbolt.org/), and on the right hand side you will see the output of the compiler you have selected.
    ```cpp
    // This is a comment, so the compiler will ignore this
    #include <iostream> // Standard header file in system directory

    int main() {
        int n = 3;
        int m = 4;
        int sum = n + m;
        return 0;
    }
    ```

# Out first program
* The following is a simple piece of code. Observe it carefully before continuing.
    ```cpp
    // Prints "Hello World"
    #include <iostream>

    int main() {
        std::cout << "Hello World!";
    }
    ```
* Lets examine this code line by line.
    * `// Prints "Hello World"` 
        * This is a comment. The compiler will ignore this line when building the machine code.
        * For multiline comments, you can open with `/*` and close with `*/`
    * `# include <iostream>`
        * `#`'s indicate directives. They are read and interpreted by the pre-processor before compilation begings.
        * This line includes the code stored in the header `iostream`, meaning it "copies and pastes" the code found there into our code, defining useful classes, functions, etc.
    * `int main()`
        * A special type of function.
        * In general, the syntax for functions is: `<type_returned> <name> (<type_arg1> <arg1>, ...)`
        * `main` function is called first when a program is run.
    * `std::cout << "Hello World!";`
        * `std::cout` identifies the standard character output device (e.g. computer screen).
        *  `<<` is the insetion operator which indicates that whatever follows should be "inserted" into `std::cout`
* Note that the end of each statement must end with a `;`
* Note that the `std` in `std::cout` refers to the namespace in which `cout` is defined (which is part of the standard library). When we add `std` this way, we are specifying that the `cout` we are referring to it the one in that namespace. In general, there are two ways of using things defined in a library: unqualified or qualified. In the example given, we used `cout` in a qualified way (we specified that it belond to the namespace `std`). However, we could have added `using namespace std;` at the beggining of our program, circumventing the need for this and allowing us to use `cout` in an unqualified fashion, as shown in the example below.
    ```cpp
    // Prints "Hello World"
    #include <iostream>
    using namespace std; // Allows all elements inthe std namespace to be accessed without the prefix `std::`

    int main() {
        cout << "Hello World!";
    }
    ```

# Variables & Types
* Line in Python, each variable needs a name/identifier to identify it. In order for an identifier to be valid it must obey the following conditions:
    * It must be a sequence of one or more letters, digits, or underscore
    * It must NOT include spaces, punctuation marks & symbols
    * It must ALWAYS begin with letter or underscore (though the latter is usually reserved for special purposes)
    * It must NOT be one of the reserved keywords in C++
* Note that C++ identifiers are case sensitive
* Each variable must have a data type when it is declared
    * Although all data will be stored somewhere in RAM as a series of 1's and 0's, the amount of memory taken by one data type might be different to another, and the bits will be interpreted differently depending on what they are said to represent.
* Base data types, also called arithmetic types:

| Group of types  | What they store              | Type names | Notes |
| --------------- | ---------------------------- | ---------- | ----- |
| Character types | Represnet a single character | char       |       |
|                 |                              | char16_t   |       |
|                 |                              | char32_t   |       |
|                 |                              | wchar_t    |       |
...

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
        ```cpp
            if (condition) statement
        ```
    * E.g.:
        ```cpp
            if (x == 100) {
                cout << "x is 100";
            }
        ```
  * `else` keyword can be used to introduce an alternative statement.
  * Syntax:
        ```cpp
            if (condition) statement1 else statement2
        ```
  * E.g.:
        ```cpp
            if (x == 100) {
                std::cout << "x is 100";
            }
            else {
                std::cout << "x is not 100";
            }
        ```
  * There also exists the equivalent of `elif` from Python. It is done as follows:
        ```cpp
            if (x > 0) 
                cout << "x is positive";
            else if (x < 0)
                cout << "x is negative";
            else
                cout << "x is 0";
        ```
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
  * `type` before parametern -> type of the n'th parameter of the function
  * Example:
        ```cpp
            #include <iostream>
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
These notes were developed using the material found in https://cplusplus.com/doc/tutorial/