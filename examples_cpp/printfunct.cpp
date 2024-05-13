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