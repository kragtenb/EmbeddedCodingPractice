#include <iostream>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <chrono>

std::shared_mutex sMtx;
int sharedData;

void writer(int x) {
    std::unique_lock<std::shared_mutex> lock(sMtx);
    sharedData = x;
    std::cout << "Writer set data to: " << sharedData << std::endl;
}

void reader(int threadNum) {
    std::shared_lock<std::shared_mutex> lock(sMtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Reader(" << threadNum << ") : " << sharedData << std::endl; 
}

int main() {
    std::thread t1(reader, 1);
    std::thread t2(writer, 5);
    std::thread t3(reader, 2);
    std::thread t4(reader, 3);

    t2.join();
    t1.join();
    t3.join();
    t4.join();

    return 0;
}