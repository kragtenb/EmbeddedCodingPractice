#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

int findFirstNotRepeated(std::vector<int> nums) {
    std::unordered_map<int, int> freq;

    for (const auto& n: nums) {
        freq[n]++;
    }

    for (const auto& n: nums) {
        if (freq[n] == 1) {
            return n;
        }
    }
    
    return -1;
}

void test_findFirstNotRepeated() {
    std::vector<int> v {4, 5, 1, 2, 0, 4, 5, 1, 2};
    assert(findFirstNotRepeated(v) == 0);
    std::vector<int> v2 {4, 4, 5, 5, 1, 1, 2, 2};
    assert(findFirstNotRepeated(v2) == -1);
}

int main() {
    test_findFirstNotRepeated();
    std::cout << "Success" << std::endl;
    return 0;
}