#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    size_t size = 10;
    std::vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }

    std::for_each(std::execution::par, data.begin(), data.end(), [](int& x) {
        x *= 2;
    });

    for (const auto& val: data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}