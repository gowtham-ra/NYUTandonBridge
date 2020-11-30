// Created by Gowtham Ra on 26/09/20.
// Program to implement the Linked List data structure

#include <iostream>
using namespace std;

template <typename T>
class Queue;

template <typename T>
class QueueNode {
    T data;
    QueueNode<T>* link;
public:
    QueueNode(T item = T(), QueueNode<T>* ptr = nullptr) : data(item), link(ptr)  {}
    friend class Queue<T>;
};

template <typename T>
class Queue {
    QueueNode<T>* front;
    QueueNode<T>* back;

public:
    void enqueue(const T& data);
    T dequeue();
    T peek();
    bool isEmpty() const { return front == nullptr; }
};

template<typename T>
void Queue<T>::enqueue(const T &data) {
    QueueNode<T>* newNode = new QueueNode<T>(data);

    if (isEmpty())
        front = back = newNode;
    else {
        back->link = newNode;
        back = newNode;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        exit(1);
    }
    else {
        QueueNode<T>* discard = front;
        T item = front->data;
        if (front == back)
            front = back = nullptr;
        else
            front = front->link;
        delete discard;
        return item;
    }
}

template<typename T>
T Queue<T>::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        exit(1);
    }
    else
        return front->data;
}

