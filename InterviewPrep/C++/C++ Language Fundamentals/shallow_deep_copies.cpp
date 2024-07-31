#include <iostream>
#include <string>
#include <memory>

class ShallowCopy {
public:
    std::string* data;

    ShallowCopy(const std::string& s) {
        data = new std::string(s);
    }

    ShallowCopy(ShallowCopy& other) {
        data = other.data;
    }

    ~ShallowCopy() {
        delete data;
    }
};

class DeepCopy {
public:
    std::string* data;

    DeepCopy(const std::string& s) {
        data = new std::string(s);
    }

    DeepCopy(DeepCopy& other) {
        data = new std::string(*(other.data));
    }

    ~DeepCopy() {
        delete data;
    }
};

int main() {
    ShallowCopy sc("Hello, Shallow World");
    ShallowCopy scCopy = sc;

    *scCopy.data = "Goodbye, Shallow World";

    DeepCopy dc("Hello, Deep World");
    DeepCopy dcCopy = dc;

    *dcCopy.data = "Goodbye, Deep World";

    std::cout << "sc: " << *sc.data << std::endl;
    std::cout << "scCopy: " << *scCopy.data << std::endl;

    std::cout << "dc: " << *dc.data << std::endl;
    std::cout << "dcCopy: " << *dcCopy.data << std::endl;
    
    // Causes Seg Fault but this code is just for representation on shallow and deep.

    return 0;
}