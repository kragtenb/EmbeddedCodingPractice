#include <iostream>

// This tells the compiler that 'T' is a placeholder for a data type
// that will be filled in when the function is called.
// This can also be used for classes.
template <typename T>
T add (T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << std::endl; // int addition
    std::cout << add(3.5, 4.5) << std::endl; // double addition
    return 0;
}