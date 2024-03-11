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