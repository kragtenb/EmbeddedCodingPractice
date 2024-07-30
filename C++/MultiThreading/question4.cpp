#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <queue>
#include <condition_variable>
#include <mutex>


class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    // Represents callable object F and provides zero or more arguments provided with ... syntax.
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::invoke_result<F, Args...>::type>;

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

    void workerThread();
};

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; i++) {
        workers.emplace_back([this] { this->workerThread(); });
    }
}

ThreadPool::~ThreadPool() {
    std::unique_lock<std::mutex> lock(queueMutex);
    stop = true;
    condition.notify_all();
    for (auto& worker: workers) {
        worker.join();
    }
}

void ThreadPool::workerThread() {
    while (true) {
        std::function<void()> task;
        std::unique_lock<std::mutex> lock(queueMutex);
        condition.wait(lock, [this] { return stop || !tasks.empty(); });
        if (stop && tasks.empty()) {
            return;
        }
        task = std::move(tasks.front());
        tasks.pop();
        task();
    }
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::invoke_result<F, Args...>::type> {
    using return_type = typename std::invoke_result<F, Args...>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> future = task->get_future();
    std::unique_lock<std::mutex> lock(queueMutex);
    if (stop) {
        throw std::runtime_error("enqueue on stopped ThreadPool");
    }
    tasks.emplace([task]() { (*task)(); });
    condition.notify_one();
    return future;
}

int main() {
    ThreadPool pool(4);

    auto result1 = pool.enqueue([] { return 42; });
    auto result2 = pool.enqueue([] (int x) { return x + 1; }, 41);

    std::cout << "Result1: " << result1.get() << std::endl;
    std::cout << "Result2: " << result2.get() << std::endl;

    return 0;
}