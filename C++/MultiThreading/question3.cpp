#include <iostream>
#include <condition_variable>
#include <mutex>
#include <shared_mutex>
#include <queue>
#include <thread>

std::condition_variable cv;
std::mutex mtx;
std::queue<int> q;
bool stop = false;

void producer(int numbersToGenerate) {
    for (int i=0; i < numbersToGenerate; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(i);
        std::cout << "Producer: Added " << i << " to the queue" << std::endl;
        cv.notify_all();
    }
    stop = true;
    cv.notify_all();
    std::cout << "Stopped producer" << std::endl;
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []() { return stop || !q.empty(); });
        if (stop && q.empty()) {
            break;
        }
        if (!q.empty()) {
            auto val = q.front();
            q.pop();
            std::cout << "Consumer: Removed " << val << " from the queue" << std::endl;
        }
    }
    std::cout << "Stopped consumer" << std::endl;
}

int main() {
    std::thread p(producer, 10);
    std::thread c(consumer);

    p.join();
    c.join();

    return 0;
}