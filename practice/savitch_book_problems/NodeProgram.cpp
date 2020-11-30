// Created by Gowtham Ra on 22/09/20.
// Program Using the Node Class

#include <iostream>
#include "Node.h"
using namespace std;
using namespace linkedListOfClasses;

void headInsert(NodePtr& head, int data) {
    NodePtr tempPtr = new Node(data, nullptr);

    if (head != nullptr)
        tempPtr->setLink(head);

    head = tempPtr;
}

int main() {
    NodePtr head, temp;

    head = new Node(0, nullptr);
    for (int i = 1; i < 5; i++)
        headInsert(head,i);

    temp = head;
    while (temp != nullptr) {
        cout << temp->getData() << endl;
        temp = temp->getLink();
    }

    temp = head;
    while (temp != nullptr) {
        NodePtr deleteNode = temp;
        temp = temp->getLink();
        delete deleteNode;
    }

    return 0;
}
