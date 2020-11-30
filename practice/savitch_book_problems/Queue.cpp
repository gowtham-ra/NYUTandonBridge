// Created by Gowtham Ra on 22/09/20.
// Program to implement queue data structure and use it in an example - Printing the word
// Items are added at the back (tail) and items are removed from the front (head)

#include <iostream>
using namespace std;

struct QueueNode {
    char data;
    QueueNode* link;
};
typedef QueueNode* QueueNodePtr;

class Queue {
public:
    Queue();
    Queue(const Queue& theQueue);
    ~Queue();
    void add(char symbol);
    char remove();
    bool empty() const;
private:
    QueueNodePtr front; //Points to the head of the linked list (Items are removed from here)
    QueueNodePtr back; //Points to the tail of the linked list (items are added here)
};

Queue::Queue() : front(nullptr), back(nullptr) {}

//Memorise this. You suck at this!
Queue::Queue(const Queue &theQueue) {
    if (theQueue.empty()) {
        front = back = nullptr;
    } else {
        QueueNodePtr tempPtrOld = theQueue.front;
        QueueNodePtr tempPtrNew;
        back = new QueueNode;
        back->data = tempPtrOld->data;
        back->link = nullptr;
        front = back;
        tempPtrOld = tempPtrOld->link;

        while (tempPtrOld != nullptr) {
            tempPtrNew = new QueueNode;
            tempPtrNew->data = tempPtrOld->data;
            tempPtrNew->link = nullptr;
            back->link = tempPtrNew;
            back = tempPtrNew;
            tempPtrOld = tempPtrOld->link;
        }
    }
}

void Queue::add(char symbol) {
    QueueNodePtr temp = new QueueNode;
    temp->data = symbol;
    temp->link = nullptr;

    if (empty()) {
        front = back = temp;

    }
    else {
        back->link = temp;
        back = temp;
    }
}

char Queue::remove() {
    if (empty()) {
        cout << "The queue is empty\n";
        exit(1);
    }
    else {
        char symbol = front->data;
        QueueNodePtr discard = front;
        front = front->link;
        if (front == nullptr)
            back = nullptr;
        delete discard;
        return symbol;
    }
}

bool Queue::empty() const {
    return (front == nullptr);
}

Queue::~Queue() {
    char next;
    while (!empty()) {
        next = remove();
    }
}

int main() {
    Queue q;
    char next, ans;

    do {
        cout << "Please enter a word\n";
        cin.get(next);
        while (next != '\n') {
            q.add(next);
            cin.get(next);
        }

        cout << "Now re-entering the word from Queue: ";
        while (!q.empty())
            cout << q.remove();
        cout << endl;

        cout << "Do you want to try again? ";
        cin.get(ans);
        cin.ignore(9999, '\n');
    } while ((ans != 'n') && (ans != 'N'));

    return 0;
}