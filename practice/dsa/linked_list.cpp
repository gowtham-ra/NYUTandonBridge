// Created by Gowtham Ra on 26/09/20.
// Program to implement the Linked List data structure

#include <iostream>
using namespace std;

template <class T>
void swap(T& item1, T& item2);

//Forward Declaration of LinkedList class
template <class T>
class LinkedList;

//Node class
template <class T>
class Node {
public:
    //Constructors
    Node() : data(T()), link(nullptr) {}
    Node(T& theData = T(), const Node<T>* theLink = nullptr) : data(theData), link(theLink) {}

    friend class LinkedList <T>;

private:
    T data;
    Node<T>* link;
};

//Linked List class
template <class T>
class LinkedList {
public:
    //Constructors
    LinkedList() : head(nullptr){}
    LinkedList(Node<T>* theList = nullptr) : head(theList) {}

    //Big 3
    LinkedList(const LinkedList<T>& rhs) : head(nullptr) {*this = recursiveCopy(rhs);} //Copy constructor
    ~LinkedList() { clear();} //Destructor
    LinkedList<T>& operator=(const LinkedList<T>& rhs); //Overloaded = operator

    //Member Functions
    void insertAtHead(T theData);
    void insertAtEnd(T theData);
    void insertAtPoint(Node<T>* ptr, T theData);
    void removeFromHead();
    int size() const;
    void clear() const;
    bool isEmpty() const {return (this->head == nullptr);}

private:
    Node<T> *head;
    Node<T>* recursiveCopy(const Node<T>*& rhs);
};

template<class T>
Node<T>* LinkedList<T>::recursiveCopy(const Node<T>*& rhs) {
    if (rhs == nullptr)
        return nullptr;
    return new Node<T>(rhs->data, recursiveCopy(rhs->link));
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    LinkedList<T> copy = rhs; //Works cos this copy will call the copy constructor
    swap(*this, copy);
    return *this;
}

template<class T>
void LinkedList<T>::insertAtHead(T theData) {
    this->head = new Node<T>(theData, this->head);
}

template<class T>
void LinkedList<T>::insertAtEnd(T theData) {
    if (isEmpty())
        head = new Node<T>(theData, nullptr);
    else {
        Node<T>* itr = this->head;
        while (itr->link != nullptr)
            itr = itr->link;
        itr->link = new Node<T>(theData, nullptr);;
    }
}

template<class T>
void LinkedList<T>::insertAtPoint(Node<T> *ptr, T theData) {
    Node<T>* itr = ptr;
    while (itr->link != nullptr)
        itr = itr->link;
    itr->link = new Node<T>(theData, nullptr);
}

template<class T>
void LinkedList<T>::removeFromHead() {
    if (isEmpty())
        return;
    else {
        Node<T>* discard = this->head;
        this->head = head->link;
        delete discard;
    }
}

template<class T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T>* itr = head;
    while (itr != nullptr) {
        count++;
        itr = itr->link;
    }
    return count;
}

template<class T>
void LinkedList<T>::clear() const {
    while (!isEmpty())
        removeFromHead();
}

template <class T>
void swap(T& item1, T& item2) {
    T temp;
    temp = item1;
    item1 = item2;
    item2 = temp;
}