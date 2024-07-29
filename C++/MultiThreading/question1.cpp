#include <iostream>
#include <thread>

void writer(int threadNum) {
    for (int i=1; i <= 5; i++) {
        std::cout << "Writer " << threadNum << ": " << i << std::endl;
    }
}

int main() {
    std::thread t1(writer, 1);
    std::thread t2(writer, 2);

    t1.join();
    t2.join();

    return 0;
}