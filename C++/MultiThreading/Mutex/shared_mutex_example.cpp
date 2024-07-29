#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
int sharedData = 0;
condition_variable cv;
bool readComplete = false;
bool writeComplete = false;


void reader() {
    unique_lock<mutex> sLock(mtx);
    cout << "Reader is reading shared data: " << sharedData << endl;
    readComplete = true;
    cv.notify_all();
}

void writer() {
    unique_lock<mutex> uLock(mtx);
    cv.wait(uLock, []() { return readComplete; });
    sharedData++;
    cout << "Writer wrote sharedData: " << sharedData << endl;
    writeComplete = true;
    cv.notify_all();
}

void reader2() {
    unique_lock<mutex> sLock2(mtx);
    cv.wait(sLock2, []() {
        return writeComplete;
    });
    cout << "Reader 2 is reading shared data: " << sharedData << endl;
    readComplete = true;
    cv.notify_all();
}

int main() {
    thread t1(reader);
    thread t2(writer);
    thread t3(reader2);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}