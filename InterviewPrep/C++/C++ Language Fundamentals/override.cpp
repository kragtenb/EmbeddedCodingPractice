#include <iostream>

class Animal {
public:
    virtual void sound() const { // Declaring sound() as a virtual function
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() const override { // Overriding the sound() function
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override { // Overriding the sound() function
        std::cout << "Meow!" << std::endl;
    }
};

void makeSound(const Animal& animal) {
    animal.sound(); // Calls the correct sound() method depending on the object type
}

int main() {
    Animal genericAnimal;
    Dog dog;
    Cat cat;

    makeSound(genericAnimal); // Outputs: Some generic animal sound
    makeSound(dog);           // Outputs: Woof!
    makeSound(cat);           // Outputs: Meow!

    return 0;
}
