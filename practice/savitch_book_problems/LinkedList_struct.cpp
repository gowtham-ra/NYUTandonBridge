// Created by Gowtham Ra on 22/09/20.
// Program to implement Linked Lists using struct

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};
typedef Node* rr;

void headInsert(rr& head, int data) {
    rr tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->link = nullptr;

    if (head != nullptr)
        tempPtr->link = head;

    head = tempPtr;
}

rr search(rr& head, int target) {
    rr tempPtr = head;

    if (head == nullptr)
        return nullptr;

    while (tempPtr != nullptr) {
        if (tempPtr->data == target)
            return tempPtr;
        else {
            tempPtr = tempPtr->link;
        }
    }
    return nullptr;
}

void insert(rr& afterMe, int data) {
    rr tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->link = afterMe->link;
    afterMe->link = tempPtr;
}