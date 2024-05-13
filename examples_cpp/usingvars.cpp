// operating with variables

#include <iostream>
using namespace std;

int main () {
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