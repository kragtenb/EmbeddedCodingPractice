#include <iostream>
#include <mutex>
#include <thread>


std::mutex mtx1;
std::mutex mtx2;

int sharedData = 0;

void threadTask(int x) {
    std::scoped_lock lock{mtx1, mtx2};
    sharedData = x;
    std::cout << sharedData << std::endl;
}


int main() {
    std::thread t1(threadTask, 20);
    std::thread t2(threadTask, 50);

    t1.join();
    t2.join();

    return 0;
}