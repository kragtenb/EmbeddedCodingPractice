#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedVar = 0;

void increment(int incrementTimes, int threadId) {
    for (int i=0; i < incrementTimes; i++) {
        std::unique_lock<std::mutex> uLock(mtx);
        int startingValue = sharedVar;
        sharedVar++;
        // std::cout << "Thread(" << threadId << ") Incremented sharedVar from " << startingValue << " to " << sharedVar << std::endl;
    }
}

int main() {
    std::thread t1(increment, 1000, 1);
    std::thread t2(increment, 1000, 2);

    t1.join();
    t2.join();

    std::cout << "Final value of sharedVar: " << sharedVar << std::endl;

    return 0;
}