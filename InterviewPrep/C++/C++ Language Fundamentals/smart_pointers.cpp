#include <iostream>
#include <memory>

void uniquePtr() {
    std::unique_ptr<int> uPtr = std::make_unique<int>(10);
    std::cout << "Unique ptr value: " << *uPtr << std::endl;
}

void sharedPtr() {
    std::shared_ptr<int> sPtr = std::make_shared<int>(20);
    std::cout << "Shared ptr value: " << *sPtr << std::endl;
}

void weakPtr() {
    std::shared_ptr<int> sPtr = std::make_shared<int>(30);
    std::weak_ptr<int> wPtr = sPtr;
    std::cout << "Shared ptr value: " << *sPtr << std::endl;
}

int main() {
    uniquePtr();
    sharedPtr();
    weakPtr();

    return 0;
}