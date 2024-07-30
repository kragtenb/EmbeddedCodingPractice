#include <iostream>
#include <barrier>
#include <thread>
#include <chrono>

std::barrier my_barrier{ 3, [] { std::cout << "All threads have reached the barrier " << std::endl; }};

void barrierTask(int x, int waitTime) {
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    std::cout << "Thread (" << x << ")  before barrier" << std::endl;
    my_barrier.arrive_and_wait();
    std::cout << "Thread (" << x << ")  after barrier" << std::endl;
}

int main() {
    std::thread t1(barrierTask, 1, 10);
    std::thread t2(barrierTask, 2, 50);
    std::thread t3(barrierTask, 3, 0);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}