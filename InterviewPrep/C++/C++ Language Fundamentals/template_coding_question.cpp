/*
Title: Implement a Generic Stack with Template Specialization

Problem Statement:
Implement a class template Stack<T> that behaves like a standard stack data structure
    (with methods push, pop, top, and isEmpty). The stack should support all data types.

Additionally, specialize the Stack class for std::string. In this specialized version,
    when a string is popped from the stack, it should be returned in all uppercase letters.

Requirements:

1. Implement the generic Stack<T> class that works for all data types.
2. Implement a full specialization of the Stack<std::string> class where the pop()
    method returns the string in uppercase.
3. The Stack<T> class should have the following methods:
    a. void push(const T& value): Pushes a value onto the stack.
    b. void pop(): Removes the top value from the stack.
    c. T top() const: Returns the top value of the stack without removing it.
    d. bool isEmpty() const: Returns true if the stack is empty, false otherwise.

Example Usage:

Stack<int> intStack;
intStack.push(1);
intStack.push(2);
intStack.push(3);
intStack.pop();          // Removes 3
std::cout << intStack.top(); // Outputs 2

Stack<std::string> stringStack;
stringStack.push("hello");
stringStack.push("world");
std::cout << stringStack.pop(); // Outputs "WORLD" in uppercase
*/

#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    void push(T val) {
        stack.push_back(val);
    }

    void pop() {
        stack.pop_back();
    }

    T top() {
        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }
private:
    std::vector<T> stack;
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.pop();          // Removes 3
    std::cout << intStack.top() << std::endl; // Outputs 2

    Stack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");
    std::cout << stringStack.top() << std::endl; // Outputs "WORLD" in uppercase

    return 0;
}