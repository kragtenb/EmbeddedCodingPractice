#include <iostream>
#include <memory>

class Resource {
public:
    Resource() {
        data = new int[100]; // Allocate resource
        std::cout << "Resource acquired" << std::endl;
    }

    ~Resource() {
        delete[] data; // Release resource
        std::cout << "Resource released" << std::endl;
    }

private:
    int* data; // Pointer to dynamically allocated array
};

void useResource() {
    Resource res;
    // Resource is acquired when res is created
    // Resource is used here
    // Resource is released automatically when res goes out of scope
}

void useUniquePtr() {
    std::unique_ptr<int[]> data = std::make_unique<int[]>(100);
    // Memory is acquired here
    // Memory is used
    // Memory is automatically released when data goes out of scope
}

int main() {
    useResource();
    useUniquePtr();
    
    return 0;
}