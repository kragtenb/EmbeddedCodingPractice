#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

template<typename T>
class LinkedList {
public:
    struct Node
    {
        T val;
        std::unique_ptr<Node> next;

        Node(T val) : val(val), next(nullptr) {}
    };
    

    LinkedList();
    explicit LinkedList(T val);

    void insert(T val);

    reverse();

    ~LinkedList();
private:
    std::unique_ptr<T>
}

#endif // LINKEDLIST_H