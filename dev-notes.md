# Set Up
We will be using GitHub codespace. Go to the repository of this tutorial and press ".". This will inititate a codespace which includes a compiler we can use.

# Compilers
* Computers only understand machine language which is composed of 1's and 0's. It is possible to write your programs in this language, but it is extremely tedious. Therefore, higher level programming languages have been developed which allow the instructions you pass to your computer to be more human readable. 
* In order to translate between the human-readable higher level languages and machine code, we use programs called compilers, interpreters or assemblers.
* C++ is a compiled language.


* Simple C++ code sample. *Go through it, pointing out important syntactical aspects, structure, etc*
```cpp
#include <iostream> // Standard header file in system directory

void print(int i){
    std::cout << "Hello World " << i << std::endl;
}

int main(int argc, char** argv) {
    int n = 3;
    for (int i = 0; i < n; i++) {
        print(i);
    }
    return 0;
}
```

# Out first program
* Take a look at the following code carefully.
```cpp
// Prints "Hello World"
#include <iostream>

int main() {
  std::cout << "Hello World!";
}
```
* Examining line by line    
    * `// Prints "Hello World"` 
        * This is a comment. The compiler will ignore this line when building the machine code.
        * For multiline comments, you can open with `/*` and close with `*/`
    * `# include <iostream>`
        * `#`'s indicate directives. They read and interpreted by the pre-processor before compilation begings.
        * This line includes the code stored in the header `iostream`, meaning it "copies and pastes" the code found there into our code, defining useful classes, functions, etc.
    * `int main()`
        * A special type of function.
        * In general, the syntax for functions is: `<type_returned> <name> (<type_arg1> <arg1>, ...)`
        * `main` function is called first when a program is run.
    * `std::cout << "Hello World!";`
        * `std::cout` identifies the standard character output device (e.g. computer screen).
        *  `<<` is the insetion operator which indicates that whatever follows should be inserted into `std::cout`
* Note that the end of each statement must end with a `;`
* Note that the `std` in `std::cout` refers to the namespace in which `cout` is defined (which is part of the standard library). When we add `std` this way, we are specifying that the `cout` we are referring to it the one in that namespace. In general, there are two ways of using things defined in a library:
    * Unqualified
        ```cpp
        // Prints "Hello World"
        #include <iostream>
        using namespace std; // Allows all elements inthe std namespace to be accessed without the prefix `std::`

        int main() {
            cout << "Hello World!";
        }
        ```
    * Qualified
        * If we don't specify the namespace using `using namespace std`, we must specify it when we use statements belonging to it.

# Variables & Types
* Line in Python, each cariable needs a name/identifier to identify it.
* Valid C++ identifiers
    * Sequence of one or more letters, digits, or underscore
    * NO spaces, punctuation marks & symbols
    * ALWAYS begins with letter or underscore (though the latter is usually reserved for special purposes)
    * Is not one of the reserved keywords in C++
* Note that C++ identifiers are case sensitive
* Each variable must have a data type when it is declared
    * Although all data will be stored somewhere in RAM as a series of 1's and 0's, the amount of memory taken by one data type vs another might not be the same, and the bits will be interpreted differently depending on what they are said to represent
* Base data types, also called arithmetic types

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

# Basic I/O

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

# Credit
These notes were developed using the material found in https://cplusplus.com/doc/tutorial/