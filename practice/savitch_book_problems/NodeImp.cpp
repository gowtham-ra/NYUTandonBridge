// Created by Gowtham Ra on 22/09/20.
// This is the implementation file Node.cpp
#include <iostream>
#include "Node.h"

namespace linkedListOfClasses {
    Node::Node() : data(0), link(nullptr) {}

    Node::Node(int value, Node *next) : data(value), link(next) {}

    int Node::getData() const {return this->data;}

    NodePtr Node::getLink() const {return this->link;}

    void Node::setData(int value) { this->data = value;}

    void Node::setLink(Node *next) {this->link = next;}
}


