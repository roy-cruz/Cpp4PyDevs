#include <iostream>

int main() {
    // Ask user for their age
    std::cout << "How old are you?\n";
    
    // Get user's age
    int age = 0;
    std::cin >> age;

    // Print a response depending on the input.
    if (age <= 5) {
        std::cout << "How are you even using a computer?\n";
    } else {
        std::cout << "Ah, so you're " << age << " years old!\n";
    }
}