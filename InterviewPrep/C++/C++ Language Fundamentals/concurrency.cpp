#include <iostream>
#include <future>
#include <thread>

int computeSquare(int x) {
    return x * x;
}


void computeSquarePromise(std::promise<int> resultPromise, int x) {
    int result = x * x;
    resultPromise.set_value(result);  // Set the result in the promise
}

int main() {
    // launch async means it will run asynchronsly in a seperate thread when started
    std::future<int> result = std::async(std::launch::async, computeSquare, 5);

    // launch deferred will differ the task until you request the result.
    std::future<int> resultDef = std::async(std::launch::deferred, computeSquare, 5);

    std::cout << "Result from async: " << result.get() << std::endl;
    std::cout << "Result from deferred: " << resultDef.get() << std::endl;

    std::promise<int> resultPromise;   // Create a promise
    std::future<int> resultFuture = resultPromise.get_future();  // Get the future from the promise

    std::thread t(computeSquarePromise, std::move(resultPromise), 5);

    // Retrieve the result from the future
    int pResult = resultFuture.get();  // This will block until the value is set in the promise

    std::cout << "Square of 5 is " << pResult << std::endl;

    t.join();  // Wait for the thread to finish

    return 0;
}